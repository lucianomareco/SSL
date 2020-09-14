#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "scanner.h"
#include "parser.h"

typedef enum
{
    Q0_inicio,
    Q1_final
} EstadoParser;

bool parser(void)
{
    EstadoParser estadoActual = Q0_inicio;
    token newToken;
    while ((newToken = GetNextToken()) != fdt)
    {
        switch (estadoActual)
        {
        case Q0_inicio:
            if ((newToken == identificador) || (newToken == constante))
            {
                estadoActual = Q1_final;
                break;
            }
            printf("Syntax error");
            return 1;
        case Q1_final:
            if ((newToken == adicion) || (newToken == producto))
            {
                estadoActual = Q0_inicio;
                break;
            }
            printf("Syntax error") ;
            return 1;  
        }
    } 
    if(estadoActual == Q0_inicio){
       printf("Syntax error") ;
            return 1;
    }
}
