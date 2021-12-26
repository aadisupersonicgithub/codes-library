
// longest palindromic prefix.
string lps(string s) {
  string tmp = s + '?';
  reverse(s.begin(), s.end());
  tmp += s;
  int n = tmp.length();
  vector<int> lps(n, 0);
  for (int i = 1; i < n; ++i) {
    int x = lps[i - 1];
    while (x > 0 && tmp[x] != tmp[i]) {
      x = lps[x - 1];
    }
    if (tmp[i] == tmp[x]) {
      ++x;
    } 
    lps[i] = x;
  } 
  string rt = tmp.substr(0, lps[n - 1]);
  return rt;
}
