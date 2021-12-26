const int BOX = 1069;
template <typename T>
struct Squirt {
    T n, kitte, ty;
    vector<T> B, a;
    T val[3] = {+MOD, -MOD, 0}; 
    Squirt(T n, T u = 0) : n(n), ty(u) {
        kitte = n / BOX + 3; 
        B.resize(kitte, val[ty]); 
        a.resize(n);
    }
    T comb(T a, T b) {
        if (ty == 0) {
            return min(a, b);    
        } else if (ty == 1) {
            return max(a, b);
        } else {
            return __gcd(a, b); 
        }        
    }
    void build(vector<T> U) {
        a = U;
        for (T i = 0; i < n; ++i) {
            T k = i / BOX;            
            B[k] = comb(B[k], a[i]);
        }
    }
    T query(T le, T ri) {
        T Le = le / BOX, Ri = ri / BOX;         
        T ans = MOD;
        for (T i = le; i <= min(ri, Le * BOX + BOX - 1); ++i) {
            ans = comb(ans, a[i]);
        }
        for (T i = Le + 1; i <= Ri - 1; ++i) {
            ans = comb(ans, B[i]);
        }
        for (T i = max(le, Ri * BOX); i <= ri; ++i) {
            ans = comb(ans, a[i]);
        }
        return ans;
    }
};
