long long numWays(long long coins[], long long n, long long net) {
  long long dp[n + 1][net + 1];
  for (long long i = 0; i <= n; i++) {
    dp[i][0] = 1; 
  }
  for (long long i = 1; i <= net; i++) {
    dp[0][i] = 0; 
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= net; j++) {
      if (j >= coins[i - 1]) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  return dp[n][net];
}
