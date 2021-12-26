vector<i64> Zed(string s) {
    i64 l = 0, r = 0, n = s.size();
    vector<i64> z(n); 
    for (i64 i = 1; i < n; i++) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n and s[i + z[i]] == s[z[i]]) { 
            z[i]++;
        }
        if (i > r)  {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z; 
}
