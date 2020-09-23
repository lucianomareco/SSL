# Calculadora 2


### Gramática Léxica

~~~
<token> -> uno de <identificador> <constante> <operadorAditivo> <operadorMultiplicador> <asignación> <igual> <carácterPuntuación>
<identificador> -> <letra> {<letra o dígito>}
<constante> -> <dígito> {<dígito>}
<letra o dígito> -> uno de <letra> <dígito>
<letra> -> una de a-z A-Z
<dígito> -> uno de 0-9
<palabraReservada> -> una de leer escribir
<operadorAditivo> -> + 
<operadorMultiplicador> -> *
<asignación> -> :=
<igual> -> =
<carácterPuntuación> -> uno de ( ) 
~~~

### Gramática Sintáctica

~~~
<programa> -> <sentencia> {<sentencia>}
<sentencia> -> <identificador> := <constante> ; |
               <expresion> =
<expresión> -> <primaria> {<operadorAditivo> | <operadorMultiplicador> <primaria>}
<primaria> -> <identificador> | <constante> |( <expresión> )
~~~

| En la entrada | Nombre del Token |
|---------------|------------------|
| := | ASIGNACION |
| = | IGUAL |
| ( | PARENIZQUIERDO |
| ) | PARENDERECHO |
| + | SUMA |
| * | MULTIPLICACION |