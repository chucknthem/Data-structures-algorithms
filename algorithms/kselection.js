/*
 * How do you find the kth largest number in an array?
 */

function swap(array, i, j) {
  var tmp = array[i];
  array[i] = array[j];
  array[j] = tmp;
}

function rpartition(array, left, right) {
  var pivot = Math.floor((left + right) / 2);
  swap(array, pivot, right);
  pivot = right;
  right--;
  while (left <= right) {
    if (array[left] < array[pivot]) {
      swap(array, left, right);
      right--;
    } else {
      left++;
    }
  }
  swap(array, left, pivot);
  return left;
}

function kselect(array, k) {
  var left = 0,
      right = array.length - 1,
      len = array.length;
  if (k > len || k <= 0) return null;
  k--;

  while (true) {
    var pivot = rpartition(array, left, right, pivot);
    if (pivot == k) break;
    if (k < pivot) {
      right = pivot - 1;
    } else {
      left = pivot + 1;
    }
  }

  console.log('p ' + pivot);
  console.log(array);
  return array[pivot];
}
var array = [6, 4, 5, 2, 1, 7, 3]
console.log(kselect(array, 0));
var array = [6, 4, 5, 2, 1, 7, 3]
console.log(kselect(array, 1));
var array = [6, 4, 5, 2, 1, 7, 3]
console.log(kselect(array, 2));
var array = [6, 4, 5, 2, 1, 7, 3]
console.log(kselect(array, 3));
var array = [6, 4, 5, 2, 1, 7, 3]
console.log(kselect(array, 4));
var array = [6, 4, 5, 2, 1, 7, 3]
console.log(kselect(array, 5));
var array = [6, 4, 5, 2, 1, 7, 3]
console.log(kselect(array, 6));
var array = [6, 4, 5, 2, 1, 7, 3]
console.log(kselect(array, 7));
var array = [6, 4, 5, 2, 1, 7, 3]
console.log(kselect(array, 8));
var array = [1, 4, 24, 58, 6, 2, 7, 23, 8]
console.log(kselect(array, 3));
