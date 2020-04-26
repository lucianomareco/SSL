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
|SEMÁNTICA |`printf("Hello world!\n");` la función `printf()` es la encargada de enviar por la salida estándar al argumento `Hello world!\n`| `std::cout << "Hello world!\n";` el operador inserccion canaliza `Hello world!\n` a través del objeto de flujo `cout` hacia la salida estándar|

