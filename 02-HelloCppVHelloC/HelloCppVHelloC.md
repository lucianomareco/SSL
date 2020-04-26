# Niveles del Lenguaje: Hello.cpp v Hello.c
---
## Objetivos
 - Analizar e identificar las diferencias entre hello.cpp y hello.c, en los tres niveles: léxico, sintáctico, y semántico
## Temas
- Lenguaje C++.
- Lenguaje C.
- Niveles del Lenguaje.
- Léxico.
- Sintaxis.
- Semántica.

## Tareas
1. Armar una tabla con similitudes y diferencias para cada uno de los tres niveles
del lenguaje, que compare ambas versiones de hello.
2. Opcional: Agregar una tercera versión en otro lenguaje de programación.

## Restricciones
- Ninguna. 

# Resolución

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
|SINTÁXIS |`printf("");` `int main (void)`|`std :: cout << "";` `int main ()` |
|SEMÁNTICA |`printf("Hello world!\n");` la función `printf()` es la encargada de enviar por la salida estándar al argumento `Hello world!\n`| `std::cout << "Hello world!\n";` el operador `<<` canaliza `Hello world!\n` a través del objeto de flujo `cout` hacia la salida estándar|

