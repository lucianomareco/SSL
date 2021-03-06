#include "../inc/scanner.h"
#include "../inc/parser.h"
#include "../inc/memory.h"
#include <stdlib.h> //exit
#include <string.h>

TOKEN tok; //Token actual

//Prototipos de funciones privadas
static void Match(tipoDeToken);
void ListaSentencias(void);
void Sentencia(void);
void Definicion(void);
int Expresion(void);
int Termino(void);
int Factor(void);

//Definición de función pública
void Parser()
{
    ListaSentencias();
    Match(FDT);
    printf("[Parser] Finalizado de manera exitosa.");
}

//Definiciones de funciones privadas
void ListaSentencias()
{
    do
        Sentencia();
    while (GetNextToken().type != FDT);
}

void Sentencia()
{
    int resultado;
    switch (GetNextToken().type)
    {
    case DEFINICION:
        Match(DEFINICION);
        Definicion(); //Asocia valor a identificador.
        break;
    case IGUAL:
        Match(IGUAL);
        resultado = Expresion();                //Expresión devuelve un resultado.
        printf("Resultado = %d \n", resultado); //Muestra resultado de la expresión.
        break;
    default:
        exit(1);
        break;
    }
    Match(FDS);
}

void Definicion()
{
    char auxName[MAX_NAME_LENGTH];
    Match(IDENTIFICADOR); //Matcheo IDENTIFICADOR
    strcpy(auxName, tok.data.name);
    Match(IGUAL);                    //Matcheo IGUAL
    Match(CONSTANTE);                //Matcheo CONSTANTE a ser asignada.
    Assign(auxName, tok.data.value); //Asignacion
}

int Expresion(void)
{
    int resultado = Termino();
    if (GetNextToken().type == SUMA)
    {
        Match(SUMA);
        resultado = resultado + Expresion();
    }
    return resultado;
}

int Termino(void)
{
    int resultado = Factor();
    if (GetNextToken().type == PRODUCTO)
    {
        Match(PRODUCTO);
        resultado = resultado * Termino();
    }
    return resultado;
}

int Factor(void)
{
    int resultado;
    switch (GetNextToken().type)
    {
    case IDENTIFICADOR:
        Match(IDENTIFICADOR);
        resultado = GetValue(tok.data.name);
        break;
    case CONSTANTE:
        Match(CONSTANTE);
        resultado = tok.data.value;
        break;
    case PARENIZQUIERDO:
        Match(PARENIZQUIERDO);
        resultado = Expresion();
        Match(PARENDERECHO);
        break;
    default:
        printf("[Parser] Error en la sintaxis.");
    }
    return resultado;
}

//--------------------------------------------------------------------
static void Match(tipoDeToken tipoEsperado)
{
    if ((tok = GetNextToken()).type != tipoEsperado)
    {
        printf("[Parser] Error en la sintaxis.\n");
        exit(3);
    }
    keepLastToken = 0;
}
