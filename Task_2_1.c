#include <stdio.h>
#include <stdlib.h>


int Min(int x, int y){
    if (x <= y) return x;
    return y;
}
int *foo(int *A, int *B,  int lenC){
    int n = 0;
    int *C;
    C = malloc(sizeof(int)*lenC);
    for (; n < lenC; n++){
        *C = *A + *B;
        C++;
        A++;
        B++;
    }
    for(int m = 0; m < lenC; m++){
        C--;
    }
    return C;
}

int main(){
    int *arrA;
    int *arrB;
    int *arrC;
    int *p;
    int lenA = 0;
    int lenB = 0;
    printf("Size of array A\n");
    scanf("%d", &lenA);
    arrA = (int *)malloc(sizeof(int)*lenA);
    printf("Size of array B\n");
    scanf("%d", &lenB);
    arrB = (int *)malloc(sizeof(int)*lenB);
    int n = 0;
    printf("%d elements for array A\n", lenA);
    for (;n < lenA; n++){
        scanf("%d", &arrA[n]);
    }
    n = 0;
    printf("%d elements for array B\n", lenB);
    for (;n < lenB; n++){
        scanf("%d", &arrB[n]); // arrB+n
    }
    int lenC = Min(lenA, lenB);
    arrC = foo(arrA, arrB, lenC);
    n = 0;
    p = arrC;
    printf("New array:\n");
    for (;n < lenC; n++){
        printf("%d ", *p);
        p++;
    }
    free(arrA);
    free(arrB);
    free(arrC);

}
