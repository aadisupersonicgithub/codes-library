long long Knapsack(long long n, long long w) {
  long long profit[500][400]; 
  memset(profit, 0, sizeof(profit));
  for (long long i = 0; i <= n; ++i) {
    for (long long j = 0; j <= w; ++j) {
      if (i == 0 or j == 0) {
        profit[i][j] = 0;
      }
      else {
        if (wt[i - 1] > j) {
          profit[i][j] = profit[i - 1][j];
        }
        else {
          profit[i][j] = max(val[i - 1] + profit[i - 1][j - wt[i - 1]], profit[i - 1][j]);
        } 
      }            
    }        
  }
  return profit[n][w];
}
