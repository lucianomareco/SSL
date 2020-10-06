#if !defined TOKEN_H
#define TOKEN_H
typedef enum
{   
    IDENTIFICADOR,
    CONSTANTE,
    ASIGNACION,
    IGUAL,
    PARENIZQUIERDO,
    PARENDERECHO,
    SUMA,
    MULTIPLICACION,
    FDS,
    FDT,
    NAT
} TOKEN;

#endif

TOKEN Scanner(void);
