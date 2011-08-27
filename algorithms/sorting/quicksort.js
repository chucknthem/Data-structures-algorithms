function swap(list, i, j) {
  var tmp = list[i];
  list[i] = list[j];
  list[j] = tmp;
}
function partition(list, low, high) {
  var mid = Math.floor((low + high)/2);
  swap(list, mid, high);
  var pivot = high;
  high--;
  while (low <= high) {
    if (list[low] >= list[pivot]) {
      swap(list, low, high);
      high--;
    } else {
      low++;
    }
  }
  swap(list, low, pivot)
  return low;
}
function quicksort(list, low, high) {
  if (low >= high) return;
  var pivot = partition(list, low, high);
  quicksort(list, low, pivot - 1);
  quicksort(list, pivot + 1, high);
}

var l = [5, 2, 1, 6, 7, 3, 2, 6, 1, 9, 8, 0, 100, 1, 35];
quicksort(l, 0, l.length - 1);
console.log(l);
