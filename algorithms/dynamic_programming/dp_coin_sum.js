function minCoinSum(coins, sum) {
  var optimal = [0];
  for (var i = 1; i <= sum; i++) {
    for (var j = 0; j < coins.length; j++) {
      var valueJ = coins[j];
      if (typeof (optimal[i]) === 'undefined' || (valueJ <= i && optimal[i - valueJ] + 1 < optimal[i])) {
        optimal[i] = optimal[i - coins[j]] + 1;
      }
    }
  }
  return optimal[sum];
}

var coins = [1, 3, 5];
var sum = 11;
for (var sum = 0; sum < 15; sum++) {
  console.log(sum + ' ' + minCoinSum(coins, sum));
}

