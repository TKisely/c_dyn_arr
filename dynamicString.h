//
// Created by Kisely Tamás on 2018. 08. 29..
//

#ifndef DYNAMICARRAY_DYNAMICSTRING_H
#define DYNAMICARRAY_DYNAMICSTRING_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct{
    char *text;
    size_t size;

}String;

String letEqual(char *input){

    String s;
    s.size=1;

    s.text = (char*)malloc(1* sizeof(char));

    while(input!='/n'||input!=NULL){

            s.size++;
            s.text=(char*)realloc(s.text, s.size* sizeof(char));


        s.text[s.size-1]=input;
    }

    return s;
}

void printOut(String *s){
    int i;
    for (i = 0; i <s->size; ++i) {
        printf("%c",s->text[i]);
    }
    printf("Finished\n");
}

void deleteString(String *s){
    s->size=0;
    free(s);
}


#endif //DYNAMICARRAY_DYNAMICSTRING_H
