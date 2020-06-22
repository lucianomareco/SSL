# Análisis comparativo. 
## C vs C++

### Lenguaje C

a. ¿El tipo es parte del lenguaje en algún nivel?

El tipo string en C se reconoce a nivel semántico como los caracteres que se encuentran dentro de "".
Mientras que a nivel léxico, solo se reconocen los caracteres individuales y a nivel sintactico se lo reconoce como
secuencia de caracteres individuales.


b. ¿El tipo es parte de la biblioteca?

Si

c. ¿Qué alfabeto usa?

{A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,
a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,
0,1,2,3,4,5,6,7,8,9,+,-,*,/,\,=,!,&,%,#,<,>,",.,,,;,:,(,),[,],{,},_,@,'}

d. ¿Cómo se resuelve la alocación de memoria?

Una cadena constante escrita como "hola mundo" es un arreglo de caracteres.
En la representación interna, el arreglo termina con el carácter nulo '\0', de tal manera que los programas puedan encontrar el fin.
La longitud de almacenamiento es asi uno más que el número de caracteres entre las comillas. El acceso a ella es a través de un apuntador a caracteres que apunta 
al primer elemento.

e. ¿El tipo tiene mutabilidad o es inmutable?

 Se pueden modificar los caracteres individuales dentro de un arreglo.
 
f. ¿El tipo es un first class citizen?

No

g. ¿Cuál es la mecánica para ese tipo cuando se los pasa como argumentos? ¿Y cuando son retornados por una función?

En C no es posible pasar arrays por valor. Al invocar a un subprograma
con un parámetro de tipo array se pasa automáticamente la dirección de dicho
array. Posteriormente, cuando se intenta acceder en el cuerpo del subprograma
a los elementos del array, se realiza (de forma automática y transparente) una
desreferencia que permite acceder a la posición de memoria adecuada.

Se debe realizar como array abierto (constante o no) o puntero a char, con las inconsistencias que ello comporta, por
ejemplo permite el operador de asignación (=) y relacionales con resultados inesperados.

No se puede declarar un array de caracteres dentro de una función, y que
la función retorne ese array. Esto provoca errores en tiempo de ejecución
complicados. 


### Lenguaje C++

a. ¿El tipo es parte del lenguaje en algún nivel?

El tipo string en C++ se reconoce a nivel semántico como los caracteres que se encuentran dentro de "".
Mientras que a nivel léxico, solo se reconocen los caracteres individuales y a nivel sintactico se lo reconoce como
secuencia de caracteres individuales.

b. ¿El tipo es parte de la biblioteca?

Si

c. ¿Qué alfabeto usa?

{A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,
a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,
0,1,2,3,4,5,6,7,8,9,+,-,*,/,\,=,!,&,%,#,<,>,",.,,,;,:,(,),[,],{,},_,@,'}

d. ¿Cómo se resuelve la alocación de memoria?



e. ¿El tipo tiene mutabilidad o es inmutable?

 Si 
 
f. ¿El tipo es un first class citizen?

No

g. ¿Cuál es la mecánica para ese tipo cuando se los pasa como argumentos? ¿Y cuando son retornados por una función?

El tipo string de la biblioteca estándar es consistente con el resto de tipos
de datos en otros aspectos y también lo es en el paso de parámetros. Por tanto,
cuando se pasa por valor uno de estos arrays se realiza una copia del valor situado
como parámetro actual. Por este motivo y para evitar la sobrecarga asociada
al proceso de copia del valor pasado, cuando este tipo vaya a ser
utilizado como valor de entrada a subprogramas deben pasarse por referencia
constante. De igual forma, cuando vayan a ser utilizados como valores de salida
o entrada/salida deben ser pasados por referencia.




