## Hello.c
~~~
#include  <stdio.h>

int main (void){
    printf("Hello world!\n");
}

~~~          
## Hello.cpp       
~~~
#include <iostream>

int main() {
    std::cout << "Hello, world!\n";     
}
~~~ 

||Hello.c  |Hello.cpp |
|---------|--------------------------------------|--------------------------------------------|
|LÉXICO |`iostream` `void`  `printf`  |  `stdio.h` `std` `::` `<<` |
|SINTÁXIS |`printf("");` |`std :: cout << "";`  |
|SEMÁNTICA |`#incluye<stdio.h>` Incluye stdio.h, que es el archivo header que contiene las definiciones de las funciones de la biblioteca estándar de C para hacer operaciones de entrada y salida. `printf("Hello world!\n");` la función `printf()` es la encargada de enviar por la salida estándar al argumento `Hello world!\n`| `#include <iostream>` Incluye iostream, que es la bioblioteca estándar en C++ para poder tener acceso a los dispositivos estándar de entrada y/o salida. `std::cout << "Hello world!\n";` el operador inserccion canaliza `Hello world!\n` a través del objeto de flujo `cout` hacia la salida estándar|

