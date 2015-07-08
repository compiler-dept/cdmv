#ifndef STACK_H
#define STACK_H

#include <stdint.h>

static const int STACK_SIZE = 256;

extern int32_t stack[STACK_SIZE];
extern uint8_t sp;

void stack_push(int32_t element);

int32_t stack_pop(void);

#endif /* end of include guard: STACK_H */
