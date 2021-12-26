
long long lpstable(string s) 
{    
  long long m = s.size(); 
  vector<vector<long long>> lpsg(m + 1, vector<long long>(m + 1, 0)); 
  string x; 
  reverse(x.begin(), x.end()); 
  for (long long i = 0; i <= m; i++) {
    lpsg[i].resize(m + 1, 0); 
  }
  for ( long long i = 0 ; i <= m ; i ++ ) {
    lpsg[i][i] = 1;
  }
  for (long long l = 2; l <= m; ++l) {
    for (long long i = 0; i <= m - l; ++i) {        
      long long j = i + l - 1;
      if (s[i] == s[j] && l == 2) {
        lpsg[i][j] = 2;
      } else if (s[i] == s[j]) {
        lpsg[i][j] = 2 + lpsg[i + 1][j - 1];
      } else {
        //max(lpsg[i + 1][j], lpsg[i][j - 1]);
        lpsg[i][j] = 0; 
      }
    }
  }
  return lpsg[0][m - 1];
}
