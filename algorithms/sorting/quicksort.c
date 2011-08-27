#include <stdio.h>
#include <malloc.h>
void printArray(int *array, int low, int high) {
	while(low <= high) {
		printf("%d ", array[low++]);
	}
	printf("\n");
}
void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
/*
 *  * pick a pivot index between low and high inclusive
 *   */
int getPivot(int *array, int low, int high) {
	return low;
}
/*
 *  * @return the position of the pivot
 *   */
int partition(int *array, int low, int high, int pivot) {
	int cur = low;
	swap(&array[pivot], &array[high]);
	 
	while (low <= high) {
		if(array[low] < array[high]) {
			swap(&array[low], &array[cur]);
			cur++;
		}
		low++;
	}
	swap(&array[cur], &array[high]);
	return cur;
}
 
void qsortLH(int *array, int low, int high) {
	if(low < high) {
		int pivot = getPivot(array, low, high);
		 
		pivot = partition(array, low, high, pivot);
		qsortLH(array, low, pivot - 1);
		qsortLH(array, pivot + 1, high);
	}
}
 
int main(int argc, char**argv) {
	int *array = (int *) malloc(sizeof(int)*8);
	array[0] = 1;
	array[1] = 4;
	array[2] = 6;
	array[3] = 58;
	array[4] = 4;
	array[5] = 2;
	array[6] = 7;
	array[7] = 23;
	printArray(array, 0, 7);
	qsortLH(array, 0, 7);
	printArray(array, 0, 7);
	return 0;
}
