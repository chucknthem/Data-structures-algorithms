function longestNondecreasingSequence(A) {
  var L = []; // Length of greatest non-decreasing sequence ending at i.
  var M = []; // Max length at i so far.
  L[0] = 0;
  M[0] = 0;
  for (var i = 1; i <= A.length; i++) {
    L[i] = 1;
    M[i] = Math.max(M[i - 1], 1);
    for (var j = 1; j < i; j++) {
      if (A[i - j - 1] <= A[i - 1] && L[i - j] + 1 > L[i]) {
        L[i] = L[i - j] + 1;
        M[i] = Math.max(L[i], M[i]);
      }
    }
  }

  console.log(L.slice(1, L.length));
  return M[A.length];
}


var A = [5, 3, 4, 8, 3, 6, 7, 5, 6, 10, 34, 23, 12, 5, 16, 19, 53, 64, 34, 35, 36, 37];
for (var i = 1; i < A.length; i++) {
  console.log(A.slice(0, i));
  console.log(i + ' ' + longestNondecreasingSequence(A.slice(0, i)));
}

