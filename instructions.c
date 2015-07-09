#include <stdio.h>
#include <stdlib.h>
#include "instructions.h"
#include "stack.h"
#include "registers.h"
#include "program.h"
#include "memory.h"

enum instructions {
    NOP,
    PUSH,
    POP,
    LOAD,
    STORE,
    JMP,
    JZ,
    JNZ,
    ADD,
    SUB,
    MUL,
    DIV,
    PRINT,
    STOP,
    MEMLOAD,
    MEMSTORE
};

union memconv {
    int32_t i32;
    uint8_t u8[2];
};

uint16_t ip = 0;

void inop(void)
{
    ip++;
}

void ipush(int32_t element)
{
    stack_push(element);

    ip += 5;
}

void ipop(void)
{
    (void)stack_pop();

    ip++;
}

void iload(uint8_t reg)
{
    stack_push(registers[reg]);

    ip += 2;
}

void istore(uint8_t reg)
{
    registers[reg] = stack_pop();

    ip += 2;
}

void ijmp(uint16_t position)
{
    ip += 3;
}

void ijz(uint16_t position)
{
    int32_t tos = stack_pop();

    if (tos == 0) {
        ip = position;
    } else {
        ip += 3;
    }
}

void ijnz(uint16_t position)
{
    int32_t tos = stack_pop();

    if (tos != 0) {
        ip = position;
    } else {
        ip += 3;
    }
}

void iadd(void)
{
    int32_t rhs = stack_pop();
    int32_t lhs = stack_pop();

    stack_push(lhs + rhs);

    ip++;
}

void isub(void)
{
    int32_t rhs = stack_pop();
    int32_t lhs = stack_pop();

    stack_push(lhs - rhs);

    ip++;
}

void imul(void)
{
    int32_t rhs = stack_pop();
    int32_t lhs = stack_pop();

    stack_push(lhs * rhs);

    ip++;
}

void idiv(void)
{
    int32_t rhs = stack_pop();
    int32_t lhs = stack_pop();

    stack_push(lhs / rhs);

    ip++;
}

void iprint(void)
{
    fprintf(stdout, "%d\n", stack_pop());

    ip++;
}

void istop(void)
{
    exit(EXIT_SUCCESS);
}

void imemload(uint8_t reg, uint32_t address)
{
    union memconv memconv;
    memconv.i32 = registers[reg];

    memory[address] = memconv.u8[0];
    memory[address + 1] = memconv.u8[1];

    ip += 6;
}

void imemstore(uint8_t reg, uint32_t address)
{
    union memconv memconv;
    memconv.u8[0] = memory[address];
    memconv.u8[1] = memory[address + 1];

    registers[reg] = memconv.i32;

    ip += 6;
}

void call_instruction(void)
{
    fprintf(stderr, "ip: %d, opcode: %d", ip, program[ip]);

    enum instructions instruction = program[ip];

    switch (instruction) {
        case NOP:
            inop();
            fprintf(stderr, "\n");
            break;
        case PUSH:
            fprintf(stderr, ", value: %d\n", get_integer(ip, 4).i32);
            ipush(get_integer(ip, 4).i32);
            break;
        case POP:
            ipop();
            fprintf(stderr, "\n");
            break;
        case LOAD:
            fprintf(stderr, ", value: %d\n", get_integer(ip, 1).u8);
            iload(get_integer(ip, 1).u8);
            break;
        case STORE:
            fprintf(stderr, ", value: %d\n", get_integer(ip, 1).u8);
            istore(get_integer(ip, 1).u8);
            break;
        case JMP:
            fprintf(stderr, ", value: %d\n", get_integer(ip, 2).u16);
            ijmp(get_integer(ip, 2).u16);
            break;
        case JZ:
            fprintf(stderr, ", value: %d\n", get_integer(ip, 2).u16);
            ijz(get_integer(ip, 2).u16);
            break;
        case JNZ:
            fprintf(stderr, ", value: %d\n", get_integer(ip, 2).u16);
            ijnz(get_integer(ip, 2).u16);
            break;
        case ADD:
            iadd();
            fprintf(stderr, "\n");
            break;
        case SUB:
            isub();
            fprintf(stderr, "\n");
            break;
        case MUL:
            imul();
            fprintf(stderr, "\n");
            break;
        case DIV:
            idiv();
            fprintf(stderr, "\n");
            break;
        case PRINT:
            fprintf(stderr, "\n");
            iprint();
            break;
        case STOP:
            fprintf(stderr, "\n");
            istop();
            break;
        case MEMLOAD:
            fprintf(stderr, ", value1: %d, value2: %d\n", get_integer(ip, 1).u8, get_integer(ip + 1, 4).u32);
            imemload(get_integer(ip, 1).u8, get_integer(ip + 1, 4).u32);
            break;
        case MEMSTORE:
            fprintf(stderr, ", value1: %d, value2: %d\n", get_integer(ip, 1).u8, get_integer(ip + 1, 4).u32);
            imemstore(get_integer(ip, 1).u8, get_integer(ip + 1, 4).u32);
            break;
    }
}
