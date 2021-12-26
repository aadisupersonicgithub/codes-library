#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")


typedef long long i64;
typedef long double ld; 
typedef pair<int, int> pi;
typedef pair<i64,i64> pl;
typedef pair<ld,ld> pd; 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<i64> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef map<int,int> mi;
typedef map<i64,i64> ml;
typedef set<int> si; 
typedef set<i64> sl;


#define trav(a,x)       for (auto& a : x)
#define uid(a, b)       uniform_int_distribution<int>(a, b)(rng)
#define nl              cout << '\n'
#define j0(x)           cout << x << ' ' 
#define j1(x)           cout << x << '\n' 
#define j2(x)           { cout << x; exit(0); } 
#define j3(x)           cout<<fixed<<setprecision(x)
#define fi              first 
#define se              second 
#define sz(x)           (x).size ()
#define fl(i,n)         for (ll i = 0; i < (n); i ++) 
#define rep(i,a,b)      for ( __typeof(b) i = (b) - ((a) > (b)); i != (b) - ((a) > (b)); i += 1 - 2 * ((a) > (b))) 
#define pb              push_back 
#define all(a)          (a).begin(), (a).end() 

#define lb              lower_bound 
#define ub              upper_bound 
#define maxe            max_element 
#define mine            min_element 
#define afill(a,n,v)    fill(a, a + n, v)  
#define asum(a,n)       accumulate ( a, a + n, 0ll )
#define albi(a,n,v)     lower_bound(a, a + n, v) - a 
#define aubi(a,n,v)     upper_bound(a, a + n, v) - a 
#define amaxi(a,n)      max_element(a, a + n) - a 
#define amini(a,n)      min_element(a, a + n) - a 
#define asort(a,n)      sort (a, a + n) 
#define vsum(v)         accumulate(v.begin() , v.end(), 0ll) 
#define vfill(v,x)      fill(v.begin() , v.end(), x)
#define vlbi(v,x)       lower_bound(v.begin(),v.end(), x ) - v.begin() 
#define vubi(v,x)       upper_bound(v.begin(),v.end(), x ) - v.begin() 
#define vmini(v)        min_element(v.begin(),v.end()) - v.begin() 
#define vmaxi(v)        max_element(v.begin(),v.end()) - v.begin()
#define vsort(v)        sort(v.begin(), v.end()) 
#define ld              long double 
#define pi_val          acos(-1.0)

void master(); 
template<typename T, typename U> void aip(U a [], T n) { for(T i = 0; i < n; i += 1) cin >> a [i]; } 
template<typename T, typename U> void aop(U a [], T n) { cout << "{ "; for(T i = 0; i < n; i += 1) cout << a [i] << " "; cout << " }\n"; } 
template<typename T, typename U> T max(T x, U y) { return((x >= y) ? x : y); } 
template<typename T, typename U> T min(T x, const U y) { return((x <= y) ? x : y); } 
template<class T> bool Min(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool Max(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
void op() { cout << "\n"; } template < typename T, typename... U > void op(T var1, U... var2) { cout << var1 << " "; op(var2...); } 
void ip() { } template < typename T, typename...Rest > void ip(T& value, Rest&&...rest) { cin >> value; ip(forward< Rest >(rest)...); }  
template<typename T> istream& operator >>(istream& orz, vector < T > &f) {  for(auto &i : f) orz >> i; return orz; } 
template<typename T> ostream& operator <<(ostream& orz, vector < T > &f) {  orz << "{"; for(auto i : f) orz << i << ", "; orz << "}\n"; return orz; } 
template<typename T> ostream& operator <<(ostream& orz, set < T > &f) { orz << "{"; for(auto i : f) { orz << i << ", "; } orz << "}\n"; return orz; } 
template<typename T> ostream& operator <<(ostream& orz, multiset < T > &f) {  orz << "{"; for(auto i : f) { orz << i << ", "; } orz << "}\n"; return orz; } 
template<typename T, typename U> ostream& operator <<(ostream& orz, map < T, U > &f) { orz << "["; for(auto i : f) orz << "(" << i.first << ", " << i.second << ") "; orz <<"]\n"; return orz;} 
template<typename T, typename U> ostream& operator <<(ostream& orz, pair < T, U > &f) { orz << "(" << f.first << ", " << f.second << ")" << " "; return orz; } 
template<typename T> ostream& operator <<(ostream& orz, queue <T> &q) { auto Q = q; orz << "{ ";  while(Q.size()) { cout << Q.front() << " "; Q.pop();  } orz << " } \n"; return orz; } 
template<typename T> ostream& operator <<(ostream& orz, stack <T> &s) { auto S = s; orz << "{ ";  while(S.size()) { cout << S.top() << " "; S.pop(); }  orz << " } \n"; return orz; } 
template <typename T, typename U> istream& operator >>(istream& orz, pair < T, U > &f) { orz >> f.first >> f.second; return orz; }

bool pal(string s) {
    bool ok = 1, ex = 1; 
    int ns = s.size();
    for (int i = 0;i < ns; i++) ex &= (s[i] == s[ns - 1 - i]);
    return ex; 
} 
bool bal(string s) {
    int open = 0, ex = 1;
    for (char c : s) (c == '(') ? (open++) :(open ? open-- : (ex = 0)); if (open) ex = 0;
    return ex ;
}
bool vowel(char c) {
    return (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u'); 
}

const i64 inf = 1e18, md1 = 1e9 + 7LL, md2 = 998244353, md3 = inf, md = md1; 
const int N1 = 200010, N2 = 5010, N3 = 510, N4 = 1e7 + 10; 


auto clk = clock();

void pre()
{
    


}

void read()
{
    
    
    
}

void solve()
{
    
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef LOCAL
        // freopen("dbg_i1.txt", "r", stdin);
        // freopen("dbg_o1.txt", "w", stdout);
        freopen("dbg_e1.txt", "w", stderr); 
    #endif
    int tt = 1;
    // cin >> tt;
    for (int tc = 1; tc <= tt; tc++)
    {
        pre();
        read();
        solve();
    }
    cerr << fixed << setprecision(4);
    cerr << "Time Elapsed: " << ((double)(clock() - clk)) / CLOCKS_PER_SEC << endl;
    return 0;
}

