#include "scanner.h"
#include "parser.h"
#include <stdlib.h>

TOKEN t;

void Parser()
{
Sentencias();
printf("\n\n\t\t--- SINTAXIS CORRECTA ---\n");
}

void Sentencias()
{
    t = Scanner();
    switch (t)
    {
    case IDENTIFICADOR: 
     printf("match ID OK: ");
        Definicion();
        Match(FDS);
         printf("match FDS OK: ");
        break;
    case EXP:
     printf("match EXP OK: ");
        Expresion();    
        TokenActual(FDS);
         printf("match FDS OK: ");
        break;
    case FDT:
     printf("match FDT OK: ");
        return;    
    default:
        ErrorSintactico();          
    }
    Sentencias();
}

void Definicion()
{
    Match(ASIGNACION);
     printf("match ASIGNACION OK: ");
    Match(CONSTANTE);
     printf("match CONSTANTE OK: ");
}

void Expresion (void) {
 Primaria();
 for (t = Scanner(); t == SUMA || t == MULTIPLICACION ; t = Scanner())
     printf("match OP OK: ");
    Primaria();
}

void Primaria(){
    t = Scanner(); 
    switch (t)
    {
        case IDENTIFICADOR:
         printf("match ID OK: ");
        return;
        case CONSTANTE:
         printf("match CONST OK: ");
        return;
        case PARENIZQUIERDO:
        while(t == PARENIZQUIERDO){
                printf("match ( OK: ");
                Expresion();
                TokenActual(PARENDERECHO);
                 printf("match ) OK: ");
        }   
        return;
        default:
        ErrorSintactico();
    }     
}
void Match(TOKEN tokenEsperado)
{
    TOKEN actualToken = Scanner();
    if (actualToken != tokenEsperado)
    {
      printf("\n\nTOKEN ESPERADO: ");
      MostrarToken(tokenEsperado);
      printf("TOKEN RECIBIDO: ");
      MostrarToken(actualToken);
      printf("\n");
      ErrorSintactico();
    }
}

void TokenActual(TOKEN tokenEsperado){
    if (tokenEsperado != t)
    {
      printf("\n\nTOKEN ESPERADO: ");
      MostrarToken(tokenEsperado);
      printf("TOKEN RECIBIDO: ");
      MostrarToken(t);
      printf("\n");
      ErrorSintactico();
    }
}

void ErrorSintactico(){
    printf("\nERROR SINTACTICO\n");
    exit(1);
}

