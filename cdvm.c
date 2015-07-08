#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

int main(int argc, char **argv) {
    stack_push(42);
    stack_push(23);

    printf("%d\n", stack_pop());
    printf("%d\n", stack_pop());

    return EXIT_SUCCESS;
}
