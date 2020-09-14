# Calculadora Infija: Construcción manual 
---

## Objetivos
+ Experimentar el diseño de la especificación de lenguajes a nivel léxico y
sintáctico.
+ Experimentar la implementación manual del nivel léxico y sintáctico de
lenguajes.

## Temas
+ Especificación del nivel Léxico y Sintáctico.
+ Implementación del nivel Léxico y Sintáctico.
+ Implementación de Scanner
+ Implementación de Parser
## Problema
Análisis de expresiones aritméticas infijas simples que incluya:
+ Números naturales con representación literal en base 10.
+ Identificadores de variables.
+ Adición.
+ Multiplicación.

## Gramática Léxica

~~~
<token> -> uno de <identificador> <constante> <operador>
    <identificador> -> <letra>
    <constante> -> <dígito>
    	<letra> -> una de a-z A-Z (a-z|A-Z)*
    	<dígito> -> uno de 0-9
    	<operador> -> uno de <adición> <producto>
    		<adición> +
    		<producto> *
~~~        
        
## Gramática Sintáctica

~~~
<expresión> -> <operando> <operador> <operando> (<operador> <operando>)*
    <operando> -> <identificador> <constante>
    <operador> -> <adición> <producto>
~~~

## AFD

<a href="https://ibb.co/4VfGnTw"><img src="https://i.ibb.co/W23w4yN/afd.png" alt="afd" border="0"></a>
