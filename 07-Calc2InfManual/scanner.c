#include "scanner.h"
#include <stdio.h>
#include <stdlib.h>



typedef enum
{
    Q0_inicial,
    Q1_identificador,
    Q2_constante,
    Q3_adicion,
    Q4_producto,
    Q5_parizquierdo,
    Q6_parderecho,
    Q7_igual,
    Q8_asignacion,
    Q9_fds,
    Q10_fdt,
    Q11_error
} Estado;
TOKEN scanner(void)

{
    static Estado estadoActual = Q0_inicial;
    char c;
    while ((c = getchar()) != EOF)
    {
        switch (estadoActual)
        {
        case Q0_inicial:
            if(isalpha(c))
            {
                estadoActual = Q1_identificador;
                break;
                }
            if(isdigit(c))
            {
                estadoActual = Q2_constante;
                break;
            }    
            if(c == '+')
            {
                estadoActual = Q3_adicion;
                break;
            }
             if (c == '*')
            {
                estadoActual = Q4_producto;
                break;
            }
             if (c == '(')
            {
                estadoActual = Q5_parizquierdo;
                break;
            }
             if (c == ')')
            {
                estadoActual = Q6_parderecho;
                break;    
            }
             if (c == '=')
            {
                estadoActual = Q7_igual;
                break;    
            }
             if (c == ':')
            {
                estadoActual = Q8_asignacion;
                break; 
            }    
             if (c == '\n')
             {
                estadoActual = Q9_fds;
        
        case Q1_identificador:
            if ((!isalpha(c)) && (!isdigit(c)))
            {
                estadoActual = Q0_inicial;
                ungetc(c, stdin);
                return IDENTIFICADOR;
            }
            break;
        case Q2_constante:
            if (!isdigit(c))
            {
                estadoActual = Q0_inicial;
                ungetc(c, stdin);
                return CONSTANTE;
            }
            break;
        case Q3_adicion:
            estadoActual = Q0_inicial;
            ungetc(c, stdin);
            return SUMA;
            break;
        case Q4_producto:
            estadoActual = Q0_inicial;
            ungetc(c, stdin);
            return MULTIPLICACION;
            break;
        case Q5_parizquierdo:
            estadoActual = Q0_inicial;
            ungetc(c, stdin);
            return PARENIZQUIERDO;
            break;  
        case Q6_parderecho:
            estadoActual = Q0_inicial;
            ungetc(c, stdin);
            return PARENDERECHO;
            break;  
        case Q7_igual: 
            estadoActual = Q0_inicial;
            ungetc(c, stdin);
            return IGUAL;
            break;  
        case Q8_asignacion:
            if(c == '='){
                estadoActual =  Q0_inicial;
                return ASIGNACION;
            }
            break;   
        case Q9_fds:
            if( c == '\n')
                return FDT;
            else
            {
            unget(c, stdin);
            return FDS;
            }
        }   
    }    
}    

void mostrar(TOKEN a)
{
    switch (a)
    {
    case IDENTIFICADOR:
        printf("id\n");
    case CONSTANTE:
        printf("const\n");
    case SUMA:
        printf("add\n");
    case MULTIPLICACION:
        printf("prod\n");
    case PARENIZQUIERDO:
        printf("prod\n");
    case PARENDERECHO:
        printf(") \n");
    case IGUAL:
        printf(" = \n");
    case ASIGNACION:
        printf(":= \n");
    case FDS:
        printf(" FDS \n");
    case FDT:
        printf(" FTD \n");    
    default:
        printf("Not a token");
        break;
    }
}
