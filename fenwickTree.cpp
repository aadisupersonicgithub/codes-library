

template<typename T> 
class Fenwick {
public : 
    T U ; vector<T> B; 
    Fenwick() {}
    Fenwick(T x) {
        U = x + 1;
        B.resize(U, 0); 
    }
    void Up(T i, T v) {                                                               
        for (i++; i < MAXN; i += (i & (-i))) {
            B[i] += v;
        }
    }
    T Get(T i) {                                                       
        T r = 0; 
        for (i++; i > 0; i -= (i & (-i))) { 
            r += B[i] ;
        }
        return r;
    }
    T Add(T i, T x) {
        Up(i, x);
        Up(i + 1, -x);
    }
    void Del(T i) {
        T x = get(i);
        Up(i, -x);
        Up(i + 1, x);
    }
    T Flift(T x) {
        T lft = 0, sum = 0;
        for (T i = 19; i >= 0; i--) { 
            T idx = (lft + ((T)(1 << i)));
            if (idx < MAXN and sum + B[idx] < x ) {
                sum += B[idx];
                lft += (1 << i);
            } 
        } 
        return lft;
    }
};
