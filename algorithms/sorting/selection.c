#include <stdio.h>
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/*
 * Selection sort.
 *
 * for i = 0..(n-1)
 *     min = i
 *      for j = i+1..(n-1)
 *          if(a[min] > a[j]) a[min] = a[j]
 *       swap(a[min], a[j])
 */
void selection(int a[], int length) {
    int i, j, min;
    for (i = 0; i < length; i++){
        min = i;
        for (j = i + 1; j < length; j++){
            if(a[min] > a[j]) {
                a[min] = a[j];
            }
        }
        swap(&a[min], &a[i]);
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
    selection(array, 10);
    printa(array, 10);
    return 0;
}
