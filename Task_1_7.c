#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int size;
    printf("Size of array: ");
    scanf("%d", &size);
    if (size <= 0) {
        printf("Try again,incorrect input\n");

        return 0;
    }
    int* arr = (int*)malloc(size * sizeof(int));
    int i;
    for (i = 0; i < size; i++) {
        arr[i] = -1000 + rand() % 2000;
    }
    printf("Array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int max_el = 0, min_el = 0;
    for (i = 1; i < size; i++) {
        if (arr[max_el] < arr[i]) max_el = i;
        if (arr[min_el] > arr[i]) min_el = i;
    }
    printf("Minimum element %d\n", arr[min_el]);
    printf("Maximum element %d\n", arr[max_el]);
    int tmp;
    tmp = arr[max_el];
    arr[max_el] = arr[min_el];
    arr[min_el] = tmp;
    printf("New array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}
