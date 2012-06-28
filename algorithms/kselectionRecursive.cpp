/**
 * This algorithm uses a quicksort like partitioning to find the k biggest
 * elements in an array.
 *
 * Expected runtime O(n + klog(k))
 */
#include <iostream>
#include <stdlib.h>

void printArray(int *array, int l, int r) {
	while(l <= r) {
		printf("%d ", array[l++]);
	}
	printf("\n");
}

int selectPivotIndex (int *array, int l, int r) {
  return (l+ r)/2;
}

void swap(int *x, int *y) {
  int t = *x;
  *x = *y;
  *y = t;
}

int partition (int *array, int l, int r) {
  int pivot = selectPivotIndex(array, l, r);
  swap(&array[pivot], &array[r]);
  pivot = r;
  r--;
  while (l <= r) {
    if (array[l] < array[pivot]) {
      swap(&array[l], &array[r]);
      r--;
    } else {
      l++;
    }
  }
  swap(&array[l], &array[pivot]);
  return l;
}

int kselect_ (int *array, int l, int r, int k) {
  int pivot = partition(array, l, r);
  if (pivot == k) {
    return array[pivot];
  }

  if (k < pivot) {
    return kselect_(array, l, pivot - 1, k);
  }

  return kselect_(array, pivot + 1, r, k);
}

// sort the array in such a way that the largest k elements
// are at array[k..len-1]
int kselect (int *array, int len, int k) {
  if (k <= 0 || k > len) return -1;
  return kselect_(array, 0, len - 1, k-1);
}

int main(int argc, char**argv) {
	int *array = (int *) malloc(sizeof(int)*8);
	array[0] = 1;
	array[1] = 4;
	array[2] = 24;
	array[3] = 58;
	array[4] = 6;
	array[5] = 2;
	array[6] = 7;
	array[7] = 23;
	array[8] = 8;
	printArray(array, 0, 8);
	int kth = kselect(array, 9, 3);
  printf("%dth largest is %d\n", 3, kth);
  printArray(array, 0, 8);
	return 0;
}

