long long rodcutting(long long pieces[], long long h, long long a, long long b, long long c) { 
  if (h < 0) {
    return -M;
  }
  if (pieces[h] != -1) {
    return pieces[h];
  }
  if (h == 0) {
    return 0;
  }
  long long ans = -M / 2;
  ans = max(ans, rodcutting(h - a, a, b, c) + 1);
  ans = max(ans, rodcutting(h - b, a, b, c) + 1);
  ans = max(ans, rodcutting(h - c, a, b, c) + 1);
  return pieces[h] = ans;
}
