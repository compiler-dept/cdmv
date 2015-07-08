#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

int32_t stack[stack_size];
uint8_t sp = 0;

void stack_push(int32_t element)
{
    if (sp == stack_size) {
        fprintf(stderr, "ERROR: %s\n", "Stack overflow occured!");
        exit(EXIT_FAILURE);
    }

    stack[sp] = element;
    sp++;
}

int32_t stack_pop()
{
    if (sp == 0) {
        fprintf(stderr, "ERROR: %s\n", "Stack underflow occured!");
        exit(EXIT_FAILURE);
    }

    return stack[--sp];
}
