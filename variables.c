#include <stdlib.h>
#include <string.h>

#include "variables.h"

struct Variable {
    char* name;
    char* value;
};

static struct Variable* variables;
static int numVariables = 0;

void initializeVariables() {
    variables = malloc(sizeof(struct Variable));
}

void setVariable(char* variable, char* value) {
    for (int i = 0; i < numVariables; i++) {
        if (strcmp(variables[i].name, variable) == 0) {
            free(variables[i].value);
            variables[i].value = strdup(value);
            return;
        }
    }
    variables = realloc(variables, (numVariables + 1) * sizeof(struct Variable));
    variables[numVariables].name = strdup(variable);
    variables[numVariables].value = strdup(value);
    numVariables++;
}

char* getVariableValue(char* variable) {
    for (int i = 0; i < numVariables; i++) {
        if (strcmp(variables[i].name, variable) == 0) {
            return variables[i].value;
        }
    }
    return NULL;
}
