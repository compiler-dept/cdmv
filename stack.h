#ifndef STACK_H
#define STACK_H

#include <stdint.h>

static const int stack_size = 256;

extern int32_t stack[stack_size];
extern uint8_t sp;

void stack_push(int32_t element);

int32_t stack_pop();

#endif /* end of include guard: STACK_H */
