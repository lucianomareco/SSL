#include <stdlib.h>
#include <stdbool.h>
#include "String.h"

size_t GetLength(const char *str){
    unsigned cont=0;
    for(unsigned i=0; str[i]!='\0'; ++i){
        ++cont;
    };
    return cont;
};

bool IsEmpty (const char *str){
    return ( str[0] == '\0');
}

void Power (const char *str , char *strout , unsigned exp){
    for(unsigned i=0; exp!=i ; ++i){
            for(unsigned j=0; str[j]!='\0' ; ++j){
                strout [j + (GetLength(str) * i)] = str[j];
            }
    }
    strout [GetLength(str) * exp] = '\0';
}

bool Compare (const char * str1, const char * str2){
    for(unsigned i=0; i <= GetLength(str1); ++i){
            if (str1[i] != str2[i])
                return 1;
    }
}
