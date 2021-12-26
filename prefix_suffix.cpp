long long n, a[MAXN]; 
long long psum[MAXN], pmax[MAXN], pmin[MAXN], pxor[MAXN], pgcd[MAXN];
long long ssum[MAXN], smax[MAXN], smin[MAXN], sxor[MAXN], sgcd[MAXN];
long long query(long long le, long long ri) {
    return psum[ri] - (le ? psum[le - 1] : 0LL);    
}
void prefsuff() 
{
    for (int i = 0; i < n; i++) {
        psum[i] = a[i];
        ssum[i] = a[i]; 
        if (i) {
            psum[i] += psum[i - 1]; 
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        ssum[i] += ssum[i + 1]; 
    }
    
    for (int i = 0; i < n; i++) {
        pmin[i] = a[i];
        smin[i] = a[i];
        if (i) {
            pmin[i] = min(pmin[i], pmin[i - 1]);
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        smin[i] = min(smin[i], smin[i + 1]); 
    }

    for (int i = 0; i < n; i++) {
        pmax[i] = a[i];
        smax[i] = a[i];
        if (i) {
            pmax[i] = max(pmax[i], pmax[i - 1]); 
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        smax[i] = max(smax[i], smax[i + 1]); 
    }

    for (int i = 0; i < n; i++) {
        pxor[i] = a[i]; 
        sxor[i] = a[i];
        if (i) {
            pxor[i] ^= pxor[i - 1];
        } 
    }
    for (int i = n - 2; i >= 0; --i) {
        sxor[i] ^= sxor[i + 1]; 
    }

    for (int i = 0; i < n; i++) {
        pgcd[i] = a[i];
        sgcd[i] = a[i]; 
        if (i) {
            pgcd[i] = __gcd(pgcd[i], pgcd[i - 1]); 
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        sgcd[i] = __gcd(sgcd[i], sgcd[i + 1]);
    }
}
