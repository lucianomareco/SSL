# Calculadora Infija: Construcción manual 
---

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
