%{
/* scanner.l
 - Reglas léxicas y TOKENs. Compilable de Flex.
 - Mareco Luciano - UTN FRBA
 - 04/03/2021
*/

#include <stdlib.h> //atoi()
#include <stdio.h>  //printf()
#include <string.h>  //strcpy()
#include "token.h" //Incluyo el header generado por bison
#define MAX_NAME_LENGTH 8
#undef YY_DECL
#define YY_DECL int GetNextToken(void)
%}
%option noyywrap

%%      

[0-9]{1,8}              {
                        yylval.value = atoi(yytext);
                        return CONSTANTE;
                        }

[a-zA-Z][a-zA-Z | 0-9]{0,7}     {
                        strcpy(yylval.name, yytext); //Copio a yylval lo que ingreso a yytext
                        return IDENTIFICADOR;
                        }

\+                      return SUMA;
        
\*                      return PRODUCTO;

\$                      return DEFINICION;

\=                      return IGUAL;
                        
\;                      return FDS;

\(                      return PARENIZQUIERDO;

\)                      return PARENDERECHO;

\!                      return FDT;

[\s\t\n]                ;

.                       return NAT;

%%
