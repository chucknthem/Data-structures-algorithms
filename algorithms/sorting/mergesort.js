function merge(left, right) {
  var l, r;
  l = r = 0;
  llen = left.length;
  rlen = right.length;
  var newArray = [];
  while (l < llen && r < rlen) {
    if (left[l] > right[r]) 
      newArray[newArray.length] = right[r++];
    else
      newArray[newArray.length] = left[l++];
  }

  while (l < llen) 
    newArray[newArray.length] = left[l++];
  while (r < rlen) 
    newArray[newArray.length] = right[r++];
  
  return newArray;
}

function mergesort(array) {
  var len = array.length; 
  if (len <= 1) return array;

  var mid = Math.min(array.length/2);
  var left = array.splice(0, mid);
  var right = array;
  left = mergesort(left);
  right = mergesort(right);

  return merge(left, right);
}

var array = [5, 6, 2, 3, 5, 7, 8, 9, 3, 3, 4];
console.log(array);
console.log(mergesort(array));

array = []
console.log(array);
console.log(mergesort(array));

array = [1]
console.log(array);
console.log(mergesort(array));

array = [2, 1]
console.log(array);
console.log(mergesort(array));
