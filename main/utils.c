#include <string.h>
#include <stdio.h>
#include "utils.h"

char** trimString(const char *inputString, int *numSubstrings){
    char copyOfString[strlen(inputString) + 1]; 
    strcpy(copyOfString, inputString);

    // Contar la cantidad de subcadenas
    *numSubstrings = 0;
    char *token = strtok(copyOfString, " ");
    while (token != NULL) {
        (*numSubstrings)++;
        token = strtok(NULL, " ");
    }

    // Reservar memoria para el array de subcadenas
    char **substrings = (char**)malloc((*numSubstrings) * sizeof(char*));

    // Volver a copiar la cadena y extraer las subcadenas
    strcpy(copyOfString, inputString);
    token = strtok(copyOfString, " ");
    int i = 0;
    while (token != NULL) {
        substrings[i] = (char*)malloc(strlen(token) + 1);
        strcpy(substrings[i], token);
        token = strtok(NULL, " ");
        i++;
    }

    return substrings;
    
}