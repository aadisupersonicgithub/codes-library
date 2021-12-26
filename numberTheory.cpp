
template <typename T, typename U> 
T max(T x, const U y) { 
    return ((x >= y) ? x : y); 
}

template <typename T, typename U> 
T min(T x, const U y) { 
    return ((x <= y) ? x : y); 
} 

template <typename T, typename U> 
void Max(T& x, U y) { 
    x = ((x >= y) ? x : y); 
}

template <typename T, typename U> 
void Min( T& x , const U y ) { 
    x = ((x <= y) ? x : y); 
} 

long long Mul(long long a, long long b) {
    return ((a % MOD) * (b % MOD)) % MOD; 
}

void Umul(long long& a, long long b) { 
    a = ((a % MOD) * (b % MOD)) % MOD; 
} 

long long Pow(long long x, long long y) { 
    long long R = 1; 
    while (y) {
        if (y & 1) {
            Umul (R, x); 
        }
        Umul (x, x); 
        y >>= 1; 
    } 
    return R; 
} 
long long Add(long long a, long long b) { 
    return (a + b + MOD) % MOD; 
}

void Uadd(long long &a, long long b) { 
    a = (a + b + MOD) % MOD; 
} 
