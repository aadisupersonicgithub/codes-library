string scstable(string a, string b) 
{
  // map<pair<long long, long long>, string> f; // A + 1 * B + 1
  long long A = a.size () , B = b.size () ; 
  vector<string> dp[A + 1];
  for (long long i = 0; i <= A; i++) {
    dp[i].resize(B + 1, " ");
  }
  for (long long i = 0; i <= A; i++) {
    for (long long j = 0; j <= B; j++) {
      if (i == 0) {
        dp[i][j] = b.substr(0, j);
      } else if (j == 0) {
        dp[i][j] = a.substr(0, i);
      } else {
        if (a[i - 1] == b[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = (dp[i][j - 1].size () < dp[i - 1][j].size() ? dp[i][j - 1] : dp[i - 1][j]);
          // dp [i][j] = min ( dp [i - 1][j], dp [i][j - 1] );
        }
      }
    }
  }
  // gr (dp) ;
  return dp[A][B];
}
