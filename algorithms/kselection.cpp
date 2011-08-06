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

int partition (int *array, int l, int r, int pivot) {
  int cur = l;
  swap(&array[pivot], &array[r]);

  while (l < r) {
    if (array[l] < array[r]) {
      swap(&array[l], &array[cur]);
      cur++;
    }
    l++;
  }
  swap(&array[cur], &array[r]);
  return cur;
}

void kselect_ (int *array, int l, int r, int k) {
  if (l< r) {
    int pivot = selectPivotIndex(array, l, r);
    pivot = partition(array, l, r, pivot);
    if (pivot > k) {
      kselect_(array, l, pivot - 1, k);
    } else if (pivot < k) {
      kselect_(array, pivot + 1, r, k);
    }
  }
}

// sort the array in such a way that the largest k elements
// are at array[k..len-1]
void kselect (int *array, int len, int k) {
  return kselect_(array, 0, len - 1, k);
}


int main(int argc, char**argv) {
	int *array = (int *) malloc(sizeof(int)*8);
	array[3] = 58;
	array[0] = 1;
	array[1] = 4;
	array[4] = 6;
	array[2] = 24;
	array[5] = 2;
	array[7] = 23;
	array[6] = 7;
	printArray(array, 0, 7);
	kselect(array, 8, 3);
	printArray(array, 0, 7);
	return 0;
}
