void subsetsum2(long long sum) {
  // space optimized 
  bool dp[sum + 1];
  memset(dp, false, sizeof(dp)); 
  dp[0] = true;
  for (int i = 0; i < n; ++i) {
    for (int j = sum; j >= a[i]; --j) {
      if (dp[j - a[i]] == 1) {
        dp[j] = 1;
      }
    }
  }
}
