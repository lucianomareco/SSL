#include "scanner.h"    

void Objetivo (void) {
/* <objetivo> -> <programa> FDT */
 Programa();
 Match(FDT);
}
void Programa(void){
    ListaDeSentencias();
}

void ListaSentencias (void) {
    Sentencia(); 
    while (1) { 
        switch (ProximoToken()) {
            case IDENTIFICADOR: case CONSTANTE: case PARENIZQUIERDO:
            Sentencia(); 
            break;
        default:
        return;
        } 
    }
}

void Sentencia(void) {
    TOKEN tok = ProximoToken();
    switch (tok) {
        case IDENTIFICADOR: /* <sentencia> -> ID := <expresion>; */
        Match(IDENTIFICADOR); Match(Asignación>)
        break;
        case LEER: /* <sentencia> -> LEER ( <listaIdentificadores> ); */
        Match(LEER); Match(PARENIZQUIERDO); ListaIdentificadores();
        Match(PARENDERECHO); Match(PUNTOYCOMA);
        break;
        case ESCRIBIR: /* <sentencia> -> ESCRIBIR (<listaExpresiones>); */
        Match(ESCRIBIR); Match(PARENIZQUIERDO); ListaExpresiones();
        Match(PARENDERECHO); Match(PUNTOYCOMA);
        break;
        default:
        ErrorSintactico(tok); break;
    }
}
