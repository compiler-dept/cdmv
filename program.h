#ifndef PROGRAM_H
#define PROGRAM_H

#include "stdlib.h"

struct value {
    uint8_t raw[];
    union {
        uint8_t u8;
        uint16_t u16;
        int32_t i32;
    };
};

static const int PROGRAM_MAX_SIZE = 65536;

extern uint8_t program[PROGRAM_MAX_SIZE];

struct value get_integer(uint16_t position, uint8_t size);

#endif /* end of include guard: PROGRAM_H */
