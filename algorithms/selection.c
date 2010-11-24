#include <stdio.h>
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/*
 * for i = 0..(n-1)
 *     min = i
 *      for j = i+1..(n-1)
 *          if(a[min] > a[j]) a[min] = a[j]
 *       swap(a[min], a[j])
 *          
 *
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
/* for i from n - 1 to 0 (inclusive)
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
    printf("\n%d\n", i);
}
struct list *bubbleL(struct list *ls) {
    int len = 0;
    int i;
    struct list *cur = ls;
    while(cur) {
        cur = cur->next;
        len++;
    }
    for(i = length - 1; i >= 0 && !isSorted; i--) {
        cur = ls;

    }
}
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
    printf("\n%d\n", i);
}
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
