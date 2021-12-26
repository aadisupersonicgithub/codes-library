long long countSubsetSum(long long ar[], long long sm, long long n) {
  long long css[sm + 1][n + 1];
  memset(css, 0, sizeof(css));
  for (long long j = 0; j <= n; ++j) {
    css[0][j] = 1;
  }
  for (long long i = 1; i <= sm; ++i) {
    css[i][0] = 0;
  }
  for (long long i = 1; i <= sm; ++i) {
    for (long long j = 1; j <= n; ++j) {
      if (css_ar[j - 1] > i) {
        css[i][j] = css[i][j - 1];
      } else {
        css[i][j] = css[i - css_ar[j - 1]][j - 1] + css[i][j - 1];
      }
    }
  }
  return css[sm][n];
}
