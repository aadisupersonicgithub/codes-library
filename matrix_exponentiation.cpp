
const int N = 2;
class matrix { public : 
    const i64 M = MOD; 
    i64 m[N][N]; 
    matrix() {
        memset(m,0,sizeof(m));
    }
    matrix operator * (matrix b) {
        matrix c = matrix();
        for (i64 i = 0; i < N; ++i)
            for (i64 k = 0; k < N; ++k)
                for (i64 j = 0; j < N; ++j) 
                    c.m[i][j] = (c.m[i][j] + 1LL * m[i][k] * b.m[k][j]) % M;
        return c;
    }
    matrix operator = (matrix a) {
        for (i64 i = 0; i < N; i++) {
            for (i64 j = 0; j < N; j++) {
                m[i][j] = a.m[i][j]; 
            }
        }
    }
    
  
};
matrix unit, p;
matrix modPow(matrix m,i64 n) {
  if (n == 0) {
    return unit; 
  }
  matrix half = modPow(m, n/2);
  matrix out = half * half;
  if ( n % 2 )
    out = out * m;
  return out; 
}
void pre() {
    unit.m[0][0] = 1;
    unit.m[0][1] = 0;
    unit.m[1][0] = 0;
    unit.m[1][1] = 1; 
    
}
/*
    // let if f[i] = 10 * f[i - 1] - 21 * f[i - 2] ;
    p.m[0][0] = 10; 
    p.m[0][1] = -21;
    p.m[1][0] = 1;
    p.m[1][1] = 0; 

    matrix d = modPow(p, i - 1); 
    // * [3 13] = {c1, c2} ans = c1; 
    i64 c1 = d.m[0][0] * 13 + d.m[0][1] * 3; 

    // let if f[i] = f[i - 1] + f[i - 2] ie fibo then p={{1, 1}, {1, 0}} 
    p.m[0][0] = 1; 
    p.m[0][1] = 1;
    p.m[1][0] = 1;
    p.m[1][1] = 0; 
    // similar as above 
*/
