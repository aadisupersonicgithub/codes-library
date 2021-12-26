
const T MAXK = 18; 
T st[MAXN][MAXK + 1], Log[MAXN+1];

void borushiki() 
{
  Log[1] = 0;
  // if id = 0, 2, 3 
  for (T i = 2; i <= MAXN; i++) {
      Log[i] = Log[i / 2] + 1;
  }        
}
template<typename T>
class Sparse { 
public:
    T ID;
    Sparse(T id) { 
        ID = id;
    }
    T help(T u1, T u2) {
        if (ID == 0) {
            return min(u1, u2); 
        } else if(ID == 1) {
            return u1 + u2; 
        } else if(ID == 2) {
            return max(u1, u2); 
        } else if (ID == 3) {
            return __gcd(u1, u2); 
        }
    }
    T query(T L, T R) { 
        T ans = 0; 
        if (ID == 0 or ID == 2 or ID == 3) { 
            T j = Log[R - L + 1];
            ans = help(st[L][j], st[R - (1 << j) + 1][j]);
        } else if (ID == 1) { 
            for (T j = MAXK; j >= 0; j--) {
                if ((1 << j) <= R - L + 1) {
                    ans += st[L][j];
                    L += 1 << j;
                }
            }
        } 
        return ans;  
    }
    void build(T ar[], T N) { 
        
        for (T i = 0; i < N; i++) {
            st[i][0] = ar[i];
        }
        for (T j = 1; j <= MAXK; j++) {
            for (T i = 0; i + (1 << j) <= N; i++) {
                st[i][j] = help(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
};
