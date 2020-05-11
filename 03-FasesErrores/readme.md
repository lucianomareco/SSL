# Fases de la Traducción y Errores
---
## Objetivos
+ Identificar las fases de traducción y errores.
## Temas
+ Fases de traducción.
+ Preprocesamiento.
+ Compilación.
+ Ensamblado.
+ Vinculación (Link).
+ Errores en cada fase.
## Tareas
1. Investigar las funcionalidades y opciones que su compilador presenta para
limitar el inicio y fin de las fases de traducción.
2. Para la siguiente secuencia de pasos:
a. Transicribir en readme.md cada comando ejecutado y
b. Describir en readme.md el resultado u error obtenidos para cada paso.
## Secuencia de pasos 
1. Escribir hello2.c, que es una variante de hello.c:
~~~
#include <stdio.h>
int/*medio*/main(void){
int i=42;
 prontf("La respuesta es %d\n");
 ~~~
2. Preprocesar hello2.c, no compilar, y generar hello2.i. Analizar su
contenido.

3. Escribir hello3.c, una nueva variante:
~~~
int printf(const char *s, ...);
int main(void){
int i=42; 
 prontf("La respuesta es %d\n");
~~~
4. Investigar la semántica de la primera línea.

5. Preprocesar hello3.c, no compilar, y generar hello3.i. Buscar diferencias
entre hello3.c y hello3.i.

6. Compilar el resultado y generar hello3.s, no ensamblar.

7. Corregir en el nuevo archivo hello4.c y empezar de nuevo, generar
hello4.s, no ensamblar.

8. Investigar hello4.s.

9. Ensamblar hello4.s en hello4.o, no vincular.

10.Vincular hello4.o con la biblioteca estándar y generar el ejecutable.

11.Corregir en hello5.c y generar el ejecutable.

12.Ejecutar y analizar el resultado.

13.Corregir en hello6.c y empezar de nuevo.

14.Escribir hello7.c, una nueva variante:
~~~
int main(void){
int i=42;
 printf("La respuesta es %d\n", i);
}
~~~~
15.Explicar porqué funciona.


## Restricciones
+ El programa ejemplo debe enviar por stdout la frase La respuesta es 42, el
valor 42 debe surgir de una variable.

# Resolucion 

2. Comando ejecutado

` gcc -E hello2.c > hello2.i `

El preprocesador agrega las siguientes sentencias:
~~~
# 1 "hello2.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "hello2.c"
~~~
Luego, reemplaza la línea #include <stdio.h> con el archivo de cabecera del sistema con ese nombre. Además reemplaza el comentario el comentario /*medio*/ por un espacio.

Por ultimo agrega otras sentencias:
~~~
# 2 "hello2.c" 2
# 2 "hello2.c"
~~~

4. Declara el prototipo de la funcion Printf() que espera de argumento un puntero a una cadena multibyte terminada en cero que especifica cómo interpretar los datos.

5. Comando ejecutado:

` gcc -E hello3.c > hello3.i`

La diferencia es que en hello3.i se agregaron las nuevas sentencias:
~~~
La diferencia es que se agregaron las nuevas líneas 
# 1 "hello3.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "hello3.c"
~~~
6. Comando ejecutado:

`gcc -S hello3.c`

Resultado:
~~~
hello3.c: In function 'main':
hello3.c:4:2: warning: implicit declaration of function 'prontf' [-Wimplicit-function-declaration]
  prontf("La respuesta es %d\n");
  ^~~~~~
hello3.c:4:2: error: expected declaration or statement at end of input
~~~
Se espera que la declaración de la función main finalice

7. Comando ejecutado:
`gcc -S hello4.c`

Resultado: 
~~~
	.file	"hello4.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "La respuesta es %d\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	call	___main
	movl	$42, 28(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE0:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
 ~~~

8. En el archivo `hello4.s` puede verse el programa en lenguaje ensamblador. Ya que La compilación transforma el código C en el lenguaje ensamblador propio del procesador de nuestra máquina.

9. Comando ejecutado:
`as -o hello4.o hello4.s`

Cuando una aplicación está compilada, normalmente no podemos acceder al código fuente como tal, sin embargo, sí es posible acceder al código compilado utilizando visores y editores de código en hexadecimal, visores que nos permiten ver el contenido exacto de un fichero. 
~~~
00	01	02	03	04	05	06	07	08	09	0A	0B	0C	0D	0E	0F	0123456789ABCDEF
000000	4C	01	06	00	00	00	00	00	C8	01	00	00	12	00	00	00	L...............
000010	00	00	04	01	2E	74	65	78	74	00	00	00	00	00	00	00	.....text.......
000020	00	00	00	00	2C	00	00	00	04	01	00	00	A0	01	00	00	....,...........
000030	00	00	00	00	03	00	00	00	20	00	30	60	2E	64	61	74	........ .0`.dat
000040	61	00	00	00	00	00	00	00	00	00	00	00	00	00	00	00	a...............
000050	00	00	00	00	00	00	00	00	00	00	00	00	00	00	00	00	................
000060	40	00	30	C0	2E	62	73	73	00	00	00	00	00	00	00	00	@.0..bss........
000070	00	00	00	00	00	00	00	00	00	00	00	00	00	00	00	00	................
000080	00	00	00	00	00	00	00	00	80	00	30	C0	2E	72	64	61	..........0..rda
000090	74	61	00	00	00	00	00	00	00	00	00	00	14	00	00	00	ta..............
0000A0	30	01	00	00	00	00	00	00	00	00	00	00	00	00	00	00	0...............
0000B0	40	00	30	40	2F	34	00	00	00	00	00	00	00	00	00	00	@.0@/4..........
0000C0	00	00	00	00	24	00	00	00	44	01	00	00	00	00	00	00	....$...D.......
0000D0	00	00	00	00	00	00	00	00	40	00	30	40	2F	31	35	00	........@.0@/15.
0000E0	00	00	00	00	00	00	00	00	00	00	00	00	38	00	00	00	............8...
0000F0	68	01	00	00	BE	01	00	00	00	00	00	00	01	00	00	00	h...............
000100	40	00	30	40	55	89	E5	83	E4	F0	83	EC	20	E8	00	00	@.0@U....... ...
000110	00	00	C7	44	24	1C	2A	00	00	00	C7	04	24	00	00	00	...D$.*.....$...
000120	00	E8	00	00	00	00	B8	00	00	00	00	C9	C3	90	90	90	................
000130	4C	61	20	72	65	73	70	75	65	73	74	61	20	65	73	20	La respuesta es 
~~~

El ensamblado transforma el programa escrito en lenguaje ensamblador a código objeto, un archivo binario en lenguaje de máquina ejecutable por el procesador.









