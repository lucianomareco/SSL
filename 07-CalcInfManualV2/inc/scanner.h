#ifndef SCANNER_H
#define SCANNER_H

#define MAX_NAME_LENGTH 20 + 1
#define MAX_CONSTANT_DIGITS 8 + 1

// Definición de flag público
int keepLastToken;

#define MAX_LEXEME_LENGTH (MAX_NAME_LENGTH + MAX_CONSTANT_DIGITS) //Deberia ser el maximo entre los dos

// Definición tipoDeToken
typedef enum
{
    NAT,
    INICIO,
    FIN,
    IDENTIFICADOR,
    CONSTANTE,
    IGUAL,
    PARENIZQUIERDO,
    PARENDERECHO,
    SUMA,
    PRODUCTO,
    DEFINICION,
    FDS,
    FDT
} tipoDeToken;

// Definición de la estructura TOKEN
typedef struct TOKEN
{
    tipoDeToken type; //Tipo
    union             //string o int
    {
        char name[MAX_NAME_LENGTH];
        int value;
    } data;
} TOKEN;

// Prototipo de funciones públicas
// Función que se encarga de devolver los TOKENs según lo que el scanner analiza.
TOKEN GetNextToken(void);
#endif