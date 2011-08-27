
/**
 * Closed form nth fibonacci number.
 */
function fibclosed(n) {
  var phi = (1 + Math.sqrt(5))/2;
  return Math.floor(Math.pow(phi, n)/Math.sqrt(5) + .5);
}

function fib(n) {
  if (n <= 0) return 0;
  if (n <= 2) return 1;
  return fib(n - 1) + fib(n - 2);
}

/**
 * Given a fibonacci number, return its index in the fibonacci sequence
 */
function reverseFib(f) {
  var phi = (1 + Math.sqrt(5))/2;
  return Math.floor(Math.log(f * Math.sqrt(5) + .5)/Math.log(phi));
}

for (var i = -4; i < 10; i++) {
  console.log(fib(i));
}
