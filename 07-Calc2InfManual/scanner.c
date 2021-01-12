#include "scanner.h"
#include "memory.h"
#include <stdio.h>  //  printf(debug)- getchar
#include <stdlib.h> // atoi
#include <ctype.h>  // isalpha - isdigit
#include <string.h> // strcopy

void mostrarTipo(TOKEN);

//-------------- PROTOTIPOS BUFFER ---------------//
void AddCharacter(char);
void ShowBuffer();
void CleanBuffer();
char buffer[10] = {0};
int bufferIndex = 0;
//-------------- PROTOTIPOS TOKENS ---------------//
TOKEN CreateToken(tipoDeToken, char[]);

//----------------- ESTADOS ---------------//
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
    Q9_expresion,
    Q10_fds,
    Q11_fdt,
    Q12_error
} State;

//---------- MAIN PARA DEBUG ---------//
int main(void)
{
    TOKEN t;
    while ((t = Scanner()).type != FDT)
    {
        mostrarTipo(t);
        printf("  ");
    };
    return 0;
}

//---------- SCANNER -----------//
TOKEN Scanner(void)
{
    static State actualState = Q0_inicial;
    static TOKEN arrivingToken;
    char c;
    while ((c = getchar()) != EOF)
    {
        switch (actualState)
        {
        case Q0_inicial:
            if (isalpha(c))
            {
                actualState = Q1_identificador;
                AddCharacter(c);
                break;
            }
            if (isdigit(c))
            {
                actualState = Q2_constante;
                AddCharacter(c);
                break;
            }
            if (c == '+')
            {
                actualState = Q3_adicion;
                break;
            }
            if (c == '*')
            {
                actualState = Q4_producto;
                break;
            }
            if (c == '(')
            {
                actualState = Q5_parizquierdo;
                break;
            }
            if (c == ')')
            {
                actualState = Q6_parderecho;
                break;
            }
            if (c == '=')
            {
                actualState = Q7_igual;
                break;
            }
            if (c == ':')
            {
                actualState = Q8_asignacion;
                break;
            }
            if (c == '$')
            {
                actualState = Q9_expresion;
                break;
            }
            if (c == '.')
            {
                actualState = Q10_fds;
                break;
            }
            if (c == '\n')
            {
                actualState = Q11_fdt;
                break;
            }
            actualState = Q12_error;
            break;

        case Q1_identificador:
            if ((!isalpha(c)) && (!isdigit(c)))
            {
                actualState = Q0_inicial;
                ungetc(c, stdin);
                arrivingToken = CreateToken(IDENTIFICADOR, buffer);
                CleanBuffer();
                return arrivingToken;
            }
            AddCharacter(c);
            break;
        case Q2_constante:
            if (!isdigit(c))
            {
                actualState = Q0_inicial;
                ungetc(c, stdin);
                arrivingToken = CreateToken(CONSTANTE, buffer);
                CleanBuffer();
                return arrivingToken;
            }
            AddCharacter(c);
            break;

        case Q3_adicion:
            actualState = Q0_inicial;
            ungetc(c, stdin);
            arrivingToken = CreateToken(SUMA, buffer);
            return arrivingToken;

        case Q4_producto:
            actualState = Q0_inicial;
            ungetc(c, stdin);
            arrivingToken = CreateToken(MULTIPLICACION, buffer);
            CleanBuffer();
            return arrivingToken;

        case Q5_parizquierdo:
            actualState = Q0_inicial;
            ungetc(c, stdin);
            arrivingToken = CreateToken(PARENIZQUIERDO, buffer);
            return arrivingToken;

        case Q6_parderecho:
            actualState = Q0_inicial;
            ungetc(c, stdin);
            arrivingToken = CreateToken(PARENDERECHO, buffer);
            return arrivingToken;

        case Q7_igual:
            actualState = Q0_inicial;
            ungetc(c, stdin);
            arrivingToken = CreateToken(IGUAL, buffer);
            return arrivingToken;

        case Q8_asignacion:
            if (c == '=')
            {
                actualState = Q0_inicial;
                arrivingToken = CreateToken(ASIGNACION, buffer);
                return arrivingToken;
            }
            actualState = Q12_error;
            break;
        case Q9_expresion:
            actualState = Q0_inicial;
            ungetc(c, stdin);
            arrivingToken = CreateToken(EXP, buffer);
            return arrivingToken;

        case Q10_fds:
            actualState = Q0_inicial;
            ungetc(c, stdin);
            arrivingToken = CreateToken(FDS, buffer);
            return arrivingToken;

        case Q11_fdt:
            if (c == '\n')
            {
                arrivingToken = CreateToken(FDT, buffer);
                return arrivingToken;
            }
            actualState = Q0_inicial;
            ungetc(c, stdin);
            break;

        case Q12_error:
            printf("[SCANNER] LEXICAL ERROR");
            c = EOF;
            exit(0);
            break;

        default:
            printf("[SCANNER] LEXICAL ERROR");
            break;
        }
    }
}

//---------- BUFFER ------------//
void AddCharacter(char c)
{
    buffer[bufferIndex] = c;
    bufferIndex++;
}
void ShowBuffer()
{
    for (int i = 0; i < 8; i++)
    {
        printf(" [%d]", buffer[i]);
    }
}
void CleanBuffer()
{
    for (int i = 0; i < 8; ++i)
    {
        buffer[i] = 0;
    }
    bufferIndex = 0;
}

//---------- MANEJO DE TOKENS ------//

TOKEN CreateToken(tipoDeToken tipo, char buffer[])
{
    TOKEN newToken;
    if (tipo == IDENTIFICADOR)
        strcpy(newToken.data.name, buffer);
    if (tipo == CONSTANTE)
        newToken.data.value = atoi(buffer);
    newToken.type = tipo;
    return newToken;
}

void mostrarTipo(TOKEN t)
{

    switch (t.type)
    {
    case IDENTIFICADOR:
        printf("IDENTIFICADOR");
        break;
    case CONSTANTE:
        printf("CONSTANTE");
        break;
    case PARENDERECHO:
        printf("PARENDERECHO");
        break;
    case PARENIZQUIERDO:
        printf("PARENIZQUIERDO");
        break;
    case ASIGNACION:
        printf("ASIGNACION");
        break;
    case IGUAL:
        printf("IGUAL");
        break;
    case FDS:
        printf("FDS");
        break;
    case FDT:
        printf("FDT");
        break;
    case MULTIPLICACION:
        printf("MULTIPLICACION");
        break;
    case SUMA:
        printf("SUMA");
        break;
    case NAT:
        printf("NAT");
        break;
    default:
        printf("otro");
        break;
    }
}
