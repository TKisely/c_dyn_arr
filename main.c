#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dynamicArray.h"
#include "dynamicString.h"

int main() {
    Array a;

//    initArray(&a, 5);
//    for (i = 0; i < 10; ++i) {
//        insertArray(&a, i);
//    }
//    printf("%d\n",a.array[2]);
//    printf("%d\n",a.used);
//    freeArray(&a);

    randomArray(&a, 20);
    arrayToString(&a);

    sortArrayMin_Max(&a);
    arrayToString(&a);

    sortArrayMax_Min(&a);
    arrayToString(&a);

    printf("%f\n",avarage_Array(&a));







    printf("Executed\n");
    return 0;
}