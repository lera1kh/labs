#include <stdio.h>
#include <stdlib.h>

int min_el(int x, int y){
    if (x == y) return x;
    if (x < y) return x;
    return y;
}
int *foo(int *A, int *B, int sizeA, int sizeB, int sizeC){
    int n = 0;
    int *C;
    C = malloc(sizeof(int)*sizeC);
    for (; n < sizeC; n++){
        *C = *A + *B;
        C++;
        A++;
        B++;
    }
    for(int m = 0; m < sizeC; m++){
        C--;
    }
    return C;
}

int main(){
    int *arrA;
    int *arrB;
    int *arrC;
    int *p;
    int sizeA = 0;
    int sizeB = 0;
    printf("Size of array A\n");
    scanf("%d", &sizeA);
    arrA = (int *)malloc(sizeof(int)*sizeA);
    printf("Size of array B\n");
    scanf("%d", &sizeB);
    arrB = (int *)malloc(sizeof(int)*sizeB);
    int n = 0;
    printf("%d elements for array A\n", sizeA);
    for (;n < sizeA; n++){
        scanf("%d", &arrA[n]);
    }
    n = 0;
    printf("%d elements for array B\n", sizeB);
    for (;n < sizeB; n++){
        scanf("%d", &arrB[n]);
    }
    int sizeC = min_el(sizeA, sizeB);
    arrC = foo(arrA, arrB, sizeA, sizeB, sizeC);
    n = 0;
    p = arrC;
    printf("New array:\n");
    for (;n < sizeC; n++){
        printf("%d ", *p);
        p++;
    }
    free(arrA);
    free(arrB);
    free(arrC);

}