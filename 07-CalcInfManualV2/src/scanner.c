#include <stdio.h>  //printf
#include <stdlib.h> //exit
#include <ctype.h>  //isalpha isdigit
#include <string.h> //strcpy
#include "scanner.h"

// Prototipos para el manejo del buffer
char buffer[MAX_LEXEME_LENGTH] = {}; //Tamanio maximo depende
void AddCharacter(char);             //Agrega caracter al buffer
void CleanBuffer();                  //Limpia el buffer
int bufferIndex = 0;

// Prototipo para la creación de TOKENs
TOKEN CreateToken(tipoDeToken);
//Prototipo para función scanner
TOKEN Scanner(void);

// Definiciones privadas ---------------------------
// Definición de estados
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
    Q8_definicion,
    Q9_fds,
    Q10_fdt,
    Q11_lexError
} State;

// Prototipos de funciones privadas ----------------
TOKEN ActionState_Qx(State, char, tipoDeToken);
void lexicalError(int);
// Declaración de variable auxiliar para mantener el último token
TOKEN incomingToken;

// Definición de funciones públicas ----------------
// Definición de la función GetNextToken
TOKEN GetNextToken(void)
{
    if (!keepLastToken)
    {
        incomingToken = Scanner();
        keepLastToken = 1;
    }
    return incomingToken;
}

// Definición de funciones privadas ----------------
// Definición de función Scanner
TOKEN Scanner()
{
    State actualState = Q0_inicial;
    char c;
    CleanBuffer();
    while ((c = getchar()) != '#') // # Marca el EOF
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
            if (c == '$')
            {
                actualState = Q8_definicion;
                break;
            }
            if (c == ';')
            {
                actualState = Q9_fds;
                break;
            }
            if (c == '\n')
            {
                actualState = Q10_fdt;
                break;
            }
            actualState = Q11_lexError;
            break;

        case Q1_identificador:
            if ((!isalpha(c)) && (!isdigit(c)))
                return ActionState_Qx(actualState, c, IDENTIFICADOR);
            AddCharacter(c);
            break;
        case Q2_constante:
            if (!isdigit(c))
                return ActionState_Qx(actualState, c, CONSTANTE);
            AddCharacter(c);
            break;

        case Q3_adicion:
            return ActionState_Qx(actualState, c, SUMA);

        case Q4_producto:
            return ActionState_Qx(actualState, c, PRODUCTO);

        case Q5_parizquierdo:
            return ActionState_Qx(actualState, c, PARENIZQUIERDO);

        case Q6_parderecho:
            return ActionState_Qx(actualState, c, PARENDERECHO);

        case Q7_igual:
            return ActionState_Qx(actualState, c, IGUAL);

        case Q8_definicion:
            return ActionState_Qx(actualState, c, DEFINICION);

        case Q9_fds:
            return ActionState_Qx(actualState, c, FDS);

        case Q10_fdt:
            if (c == '!')
                return CreateToken(FDT);
            actualState = Q0_inicial;
            ungetc(c, stdin);
            break;

        case Q11_lexError:
        default:
            lexicalError(4);
            //c = '#';
            //ungetc(c, stdin);
            //break;
        }
    }
    //exit(4);
}

//---------- BUFFER ------------//
void AddCharacter(char c)
{
    if (bufferIndex >= MAX_LEXEME_LENGTH)
        lexicalError(5);
    buffer[bufferIndex] = c;
    bufferIndex++;
}

void CleanBuffer()
{
    memset(buffer, 0, sizeof buffer);
    bufferIndex = 0;
}

//---------- MANEJO DE TOKENS ------//

TOKEN CreateToken(tipoDeToken tipo)
{
    TOKEN newToken;
    switch (tipo)
    {
    case IDENTIFICADOR:
        if (strlen(buffer) > sizeof newToken.data.name)
            lexicalError(6);
        strcpy(newToken.data.name, buffer);
        break;
    case CONSTANTE:
        if (strlen(buffer) > MAX_CONSTANT_DIGITS)
            lexicalError(7);
        newToken.data.value = atoi(buffer);
        break;
    }
    newToken.type = tipo;
    return newToken;
}

TOKEN ActionState_Qx(State state, char c, tipoDeToken type_Qx)
{
    state = Q0_inicial;
    ungetc(c, stdin);
    return CreateToken(type_Qx);
}

void lexicalError(int numError)
{
    switch (numError)
    {
    case 4:
        printf("\n[Scanner]  El caracter no pertenece al alfabeto soportado.\n\n");
        exit(4);
    case 5:
        printf("\n [Scanner] La longitud del LEXEMA es demasiada larga. \n");
        exit(5);
    case 6:
        printf("\n [Scanner] La longitud del IDENTIFICIADOR es demasiada larga. \n");
        exit(6);
    case 7:
        printf("\n [Scanner] La longitud de la CONSTANTE es demasiada larga. \n");
        exit(7);
    default:
        exit(-1);
    }
}