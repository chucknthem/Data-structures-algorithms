#include <stdio.h>
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/* 
 * Bubble sort with early exit. 
 *
 * for i from n - 1 to 0 (inclusive)
 *      for j from 0 to i - 2 (inclusive)
 *          if(j > j+1) swap(j, j+1)
 */
void bubble(int array[], int length) {
    int i,j;
    int isSorted = 0;
    for(i = length - 1; i >= 0 && !isSorted; i--) {
        isSorted = 1;
        for(j = 0; j < i; j++) {
            if(array[j] > array[j+1]) {
                isSorted = 0;
                swap(&array[j], &array[j+1]);
            }
        }
    }
}

/*
 * Naive bubble sort.
 */
void bubblen(int array[], int length) {
    int i,j;
    int isSorted = 0;
    for(i = length - 1; i >= 0 && !isSorted; i--) {
        for(j = 0; j < i; j++) {
            if(array[j] > array[j+1]) {
                swap(&array[j], &array[j+1]);
            }
        }
    }
}

/*
 * Print Array.
 */
void printa(int array[], int len) {
    int j;
    for(j = 0; j < len; j++) {
        printf("%d ", array[j]);
    }
    printf("\n");
}

int main(void) {
    int array[10] = {3, 5, 1, 4, 5, 2, 4, 7, 12, 13};
    printa(array, 10);
    bubble(array, 10);
    printa(array, 10);
    return 0;
}
