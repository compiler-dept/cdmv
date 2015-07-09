#include <stdlib.h>
#include <stdio.h>
#include "program.h"
#include "instructions.h"

int main(int argc, char **argv) {
    FILE *f = fopen(argv[1], "r");
    if (!f) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    uint16_t i = 0;
    do {
        program[i++] = (uint8_t)fgetc(f);;
    } while(!feof(f));

    if (ferror(f)) {
        perror("fgetc");
        return EXIT_FAILURE;
    }

    fclose(f);

    while(1) {
        call_instruction();
    }

    return EXIT_SUCCESS;
}
