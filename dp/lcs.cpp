
vector<long long> lcsg[N];
string lcsd(string s1, string s2) 
{
  long long n1 = s1.size(), N = s2.size();     
  for (long long i = 0; i <= n1; i++) {
    lcsg[i].resize(N + 1, 0); 
  }
  long long lcsb = 0;
  for (long long i = 1; i <= n1; i++) {
    for (long long j = 1; j <= N; j++) {          
      if (s1[i - 1] == s2[j - 1]) {
        lcsg[i][j] = lcsg[i - 1][j - 1] + 1;
      } else {
        lcsg[i][j] = max (lcsg[i][j - 1], lcsg[i - 1][j]); 
        // lcsg [i][j] = 0; // substr
      }
      lcsb = max (lcsb, lcsg[i][j]);
    }
  }
  // gr (lcsg) ; // return lcsb ; substr // return lcsg [n1][N] ; subseq 
  string f, ans;
  long long i = n1, j = N;    
  for ( ; i > 0 and j > 0; ) {
    if (s1[i - 1] == s2[j - 1]) {
      f += s1 [i - 1];
      i -= 1; 
      j -= 1;
    } else {
      // cmt this for subseq ow substr
      if (f.size()) { 
        if (f.size() > ans.size()) {
          ans = f;
          f = "" ; 
        }
      }
      if (lcsg [i - 1][j] > lcsg [i][j - 1]) {
        i -= 1; 
      } else {
        j -= 1; 
      }
    }
  }
  // reverse(ans.begin(), ans.end()); return ans; // substr
  reverse(f.begin(), f.end());
  return f; 
}
