#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int *array;
    size_t used;
    size_t size;
}Array;

typedef struct{
    char *text;
    size_t used;
    size_t size;

}String;

void initArray(Array *a, size_t initialSize){
    a->array = (int*)malloc(initialSize* sizeof(int));
    a->used=0;
    a->size=initialSize;
}

void insertArray(Array *a, int element){
    if(a->used==a->size){
        a->size++;
        a->array=(int*)realloc(a->array, a->size* sizeof(int));
    }

    a->array[a->used++]=element;
}

void freeArray(Array *a){
    free(a->array);
    a->array=NULL;
    a->used=a->size=0;
}

void randomArray(Array *a, int size){
    int i;
    srand(time(NULL));


    initArray(a, size);
    for (i = 0; i < size; ++i) {
        insertArray(a, (rand()%size));
    }

}

void arrayToString(Array *a){
    int i;
    for (i = 0; i <a->size; ++i) {
        printf("%d\t",a->array[i]);
    }
    printf("Finished\n");
}

void sortArrayMin_Max(Array *a){
    int i;
    int j;
    int temp;
//    Array temp;
//    initArray(&temp, a->size);

    for (i = 0; i < (a->size)-1; ++i) {
        for (j = 0; j < (a->size)-i-1; ++j) {
            if(a->array[j]>a->array[j+1]){
                temp=a->array[j];
                a->array[j]=a->array[j+1];
                a->array[j+1]=temp;
            }
        }
    }

}

void sortArrayMax_Min(Array *a){
    int i;
    int j;
    int temp;

    for (i = 0; i < (a->size)-1; ++i) {
        for (j = 0; j < (a->size)-i-1; ++j) {
            if(a->array[j]<a->array[j+1]){
                temp=a->array[j];
                a->array[j]=a->array[j+1];
                a->array[j+1]=temp;
            }
        }
    }
}

double avarage_Array(Array *a){
    int i;
    float sum=0;
    double ret;

    for (int i = 0; i < a->size; ++i) {
        sum+=a->array[i];
    }
    ret=sum/a->size;
    return ret;

}



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