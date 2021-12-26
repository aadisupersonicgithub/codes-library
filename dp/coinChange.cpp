void coinChange2() {
    // space optimized 
    long long c[3] = {1, 3, 5};
    long long f[105] = {0} ; f[0] = 1;
    for (long long i = 0; i < 3; i++) {
      for (long long j = c[i]; j <= 105; j++) {
        f[j] += f[j - c[i]];
      }
    } 
    cout << f[n] << endl; 
}
