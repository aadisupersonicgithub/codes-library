bool subsetSum(long long ar[], long long x, long long n) {
  long long have[x + 1][n + 1];
  for (long long j = 0; j <= n; ++j) {
    have[0][j] = 1;
  }
  for (long long i = 1; i <= x; ++i) {
    have[i][0] = 0;
  }
  for (long long i = 1; i <= x; ++i) {
    for (long long j = 1; j <= n; ++j) {
      if (ar[j - 1] > i) {
        have[i][j] = have[i][j - 1];
      } else {
        have[i][j] = have[i - ar[j - 1]][j - 1] || have[i][j - 1];
      }
    }
  }
  return have[x][n];
}
