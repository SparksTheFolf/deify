#include <stdio.h>
#include <stdlib.h>

#include "tokenizer.h"
#include "interpreter.h"

int main() {
    char* code = "x: 10\n"
                 "y: 5\n"
                 "z: x + y\n"
                 "pln(\"Result: \" + z:int)";

    char** tokens = tokenize(code);
    interpret(tokens);

    // Free memory
    for (int i = 0; tokens[i] != NULL; i++) {
        free(tokens[i]);
    }
    free(tokens);

    return 0;
}
