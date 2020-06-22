# Archivo makefile para compilar StringTest.c
# Luciano Gaston Mareco
# 22/06/2020

StringTest: String.o
	gcc -o StringTest String.o

String.o: String.c String.h
	gcc -c String.c

clean:
	rm -f String *.o