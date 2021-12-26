
void unboundedKnap(long long wt[], long long val[], long long w, long long n) 
{
  long long dp[w + 1][n + 1]; 
  memset(dp, 0, sizeof(dp));
  for (long long i = 1; i <= w; ++i) {
    for (long long j = 1; j <= n; ++j) {
      if (wt[j - 1] <= i) {
        dp[i][j] = max(dp[i][j - 1], val[j - 1] + dp[i - wt[j - 1]][j]);
      } else {
        dp[i][j] = dp[i][j - 1];
      }
    }
  }
  cout << dp[w][n] << " " ; 
}
