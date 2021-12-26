void clearlsbtoith(long long &x, long long i) { long long mask = ~((1LL << (i + 1)) - 1LL); x &= mask ; }
void clearmsbtoith(long long &x, long long i) { long long mask = (1LL << i) - 1; x &= mask; }
void striplsb(long long& x) { x &= ( x - 1LL ) ; }
void shiftri(long long& x, long long i) { x >>= i ; }
void shiftli(long long& x, long long i) { x <<= i; }
long long getlsb(long long x) { return (x & (-x)); }
long long ispow2(long long x) { return x and !(x & (x - 1LL)); }
long long msbi(long long x) { for (long long i = 63ll; i >= 0LL; i--) if (x & (1LL << i)) return i;}
long long lsbi(long long x) { for (long long i = 0LL; i <= 63; i++) if (x & (1LL << i)) return i;}
long long maski(long long i) { return (1LL << i) - 1; }
bool isset2(long long k, long long i) { return ((k >> i) & 1) > 0LL; }  
long long bitidx(long long x) { return (x ? (long long)log2(x) : 0LL); }
