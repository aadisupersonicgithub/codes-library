long long Inv(long long a) { 
  return Pow(a, MOD - 2) % MOD; 
}
long long ift[MAXN], ft[MAXN];
void Fact() { 
  ft[0] = ift[0] = 1ll; 
  for (long long i = 1; i < MAXN; ++i) { 
    ft[i] = Mul(ft[i - 1], i); 
    ift[i] = Inv(ft[i]); 
  } 
}
long long nCr(long long n, long long r) { 
  return  Mul(ft[n], Inv(Mul(ft[r], ft[n - r]))); 
}
long long tmp8 = 0 , tmp9 = 1; 
void iadd() {} template <typename T, typename... U> 
void iadd(T var1 , U... var2) { 
  Uadd(tmp8 , var1); 
  iadd(var2...);
}
void imul() {} template <typename T, typename... U> 
void imul(T var1 , U... var2) { 
  Umul(tmp9 , var1); 
  imul(var2...); 
} 
double nCr(double n, double r) {
  double P = 1.0; 
  if (r > n) {
    return 0.0; 
  }
  for (int i = 0; i < r; ++i) {
    P *= (n - i) * (double)1.0 / (i + 1); 
  } 
  return P; 
}
