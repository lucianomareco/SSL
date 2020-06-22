# Especificación matemática
## GetLength 

GetLength : Σ* --> |N

~~~
GetLength (s) = | 0                   if s = ε
                | 1 + GetLength(t)    if s = h.t and h ϵ Σ
~~~                
## IsEmpty 

IsEmpty : Σ* --> |B
~~~
IsEmpty (s) = | V      if s = ε
              | F      E.O.C.
~~~              

## Power

Power : Σ* x |N --> Σ*
~~~
Power (s,n) : | ε                   if n = 0
              | Σ*. Power (s,n-1)   E.O.C.
~~~

## Compare

Compare :  Σ* x Σ* --> |B

~~~
Compare(s1,s2) : | F     if s1 = s2
                 | V     E.O.C.
