#include <stdlib.h>
#include <string.h>

#include "tokenizer.h"

char** tokenize(char* code) {
    int numTokens = 0;
    char** tokens = malloc(sizeof(char*));
    char* token = strtok(code, "\n");
    while (token != NULL) {
        tokens[numTokens] = strdup(token);
        numTokens++;
        tokens = realloc(tokens, (numTokens + 1) * sizeof(char*));
        token = strtok(NULL, "\n");
    }
    tokens[numTokens] = NULL;
    return tokens;
}
