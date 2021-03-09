#ifndef MEMORY_H
#define MEMORY_H

#include "scanner.h" // Para saber la longitud maxima del nombre de la variable.

// Definición de la estructura variable
typedef struct variable
{
    char name[MAX_NAME_LENGTH];
    int value;
} variable;

#endif

// Prototipos de funciones públicas para el manejo de memoria.
void Assign(char[], int);
int GetValue(char[]);