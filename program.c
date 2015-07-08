#include "program.h"

uint8_t program[PROGRAM_MAX_SIZE];

struct value get_integer(uint16_t position, uint8_t size)
{
    struct value value;

    switch (size) {
        case 1:
            value.raw[0] = program[position + 1];
            break;
        case 2:
            value.raw[0] = program[position + 2];
            value.raw[1] = program[position + 1];
            break;
        case 4:
            value.raw[0] = program[position + 4];
            value.raw[1] = program[position + 3];
            value.raw[2] = program[position + 2];
            value.raw[3] = program[position + 1];
            break;
    }

    return value;
}
