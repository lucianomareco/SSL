C++------------------------------------------------------------

#include <iostream>

int main() {
    std::cout << "Hello, world!\n";     
}

C---------------------------------------------------------

#include  <stdio.h>

int main (void){
    printf("Hello world!\n");
}
          
                C                                                     C++
                
LEXICO        iostream void  printf                                      stdio.h,  std, ::, <<


SINTAXIS      printf("");                                                std :: cout << "";       
              
SEMANTICA     int main(void)                                             int main()
              int main () se puede llamar con cualquier                  int main() e int main(void) no tienen
              argumento, pero int main (void) solo                       diferencia
              se puede llamar sin ningún argumento.
              
              , puede hacer printf ()              
              para enviar una cadena formateada a un archivo          
              o alguna otra de la misma familia. Todos son parte 
              del estándar C.

std::cout << "Hello world!\n";  

el operador inserccion canaliza "Hello world!\n" a traves del objeto de flujo cout hacia la salida estandar

la funcion printf() es la encargada de enviar por la salida standar al argumento "Hello world!\n"



#include <iostream>
Incluye iostream, que es la bioblioteca estándar en C++ para poder tener acceso a los dispositivos estándar de entrada y/o salida.

#incluye<stdio.h>
Incluye stdio.h,que es el archivo de cabecera que contiene las definiciones de las macros, las constantes, 
las declaraciones de funciones de la biblioteca estándar del lenguaje de programación C para hacer operaciones, 
estándar, de entrada y salida, así como la definición de tipos necesarias para dichas operaciones. 