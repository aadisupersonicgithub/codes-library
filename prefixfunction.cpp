vector<i64> Prefix(string s) {
    i64 n = s.size(); 
    vector<i64> a(n); 
    for ( i64 i = 1; i < n; i++) {
        i64 j = a[i - 1];
        while (j > 0 and s[i] != s[j]) {
            j = a[j - 1] ;
        }
        if (s[i] == s[j]) {
            j++;
        }
        a[i] = j;
    }
    return a; 
}
