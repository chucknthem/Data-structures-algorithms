function search(array, value) {
  var left = 0,
      right = array.length - 1;
  while (left <= right) {
    var mid = Math.floor((left + right) / 2);
    if (array[mid] == value) {
      return true;
    }
    if (array[mid] < value) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return false;
}

var array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
console.log(search(array, 1));
console.log(search(array, 2));
console.log(search(array, 3));
console.log(search(array, 4));
console.log(search(array, 5));
console.log(search(array, 6));
console.log(search(array, 7));
console.log(search(array, 8));
console.log(search(array, 9));
console.log(search(array, 10));
console.log(search(array, 100));
