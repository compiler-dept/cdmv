#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <stdint.h>

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
    STOP
};

extern uint16_t ip;

void inop(void);
void ipush(int32_t element);
void ipop(void);
void iload(uint8_t reg);
void istore(uint8_t reg);
void ijmp(uint16_t position);
void ijz(uint16_t position);
void ijnz(uint16_t position);
void iadd(void);
void isub(void);
void imul(void);
void idiv(void);
void iprint(void);
void istop(void);

void call_instruction(void);

#endif /* end of include guard: INSTRUCTIONS_H */
