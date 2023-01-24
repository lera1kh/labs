#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int size = 5;
    int arr[size];
    for (int i = 0; i < size; i++){
        arr[i] = rand() % 1000;
        printf("%d ", arr[i] );
    }
    printf("\n");

    int max_el = INT_MIN;
    int ind_max;
    int min_el = INT_MAX;
    int ind_min;
    for (int i = 0; i < size; i++) {
        if (arr[i] > max_el){
            max_el = arr[i];
            ind_max = i;
        }
        if (arr[i] < min_el){
            min_el = arr[i];
            ind_min = i;
        }
    }
    int tmp;
    tmp = arr[ind_max];
    arr[ind_max] = arr[ind_min];
    arr[ind_min] = tmp;

    for (int i = 0; i < size; i++){
        printf("%d ", arr[i] );
    }
    printf("\n");
    return 0;
}
