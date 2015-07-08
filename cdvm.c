#include <stdlib.h>
#include "program.h"
#include "instructions.h"

int main(int argc, char **argv) {
    uint16_t i = 0;

    program[i++] = 0x01; // PUSH
    program[i++] = 0x00;
    program[i++] = 0x00;
    program[i++] = 0x00;
    program[i++] = 0x2a; // 42

    program[i++] = 0x01; // PUSH
    program[i++] = 0x00;
    program[i++] = 0x00;
    program[i++] = 0x00;
    program[i++] = 0x17; // 23

    program[i++] = 0x08; // ADD

    program[i++] = 0x0c; // PRINT

    program[i++] = 0x00; // NOP

    program[i++] = 0x0d; // STOP

    while(1) {
        call_instruction();
    }

    return EXIT_SUCCESS;
}
