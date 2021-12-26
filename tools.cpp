map<char, int> CI;
map<int, char> IC;
long long tw[MAXN], ten[MAXN]; 
void tools_init() {
    for (char c = 'A' ; c <= 'Z' ; c ++ ) {
        int x = c - 'A' + c;
        CI[c] = x ; 
        IC[x] = c; 
    }
    tw[0] = ten[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        tw[i] = Mul(tw[i - 1], 2);
        ten[i] = Mul(ten[i - 1], 10); 
    }

    sort(f.begin(), f.end()); 
    f.erase(unique(f.begin(), f.end()), f.end()); 
    /*
    * keeps all distint
    * unique removes all duplicates and returns iterator to last distinct after that garbage in f 
    * used erase to remove garbage
    */
}


// compression_key
map<long long, long long> fr, ba;
void compress2(vector<long long> &pts) {
    sort(pts.begin(), pts.end()); 
    pts.erase(unique(pts.begin(), pts.end()), pts.end()); 
    long long c = 1; 
    for (auto i : pts) {
        fr[i] = c;
        ba[c] = i;
        c++; 
    }
}
i64 subarray(i64 rq) {
    i64 c = 0, ans = 0;
    map<i64, i64> f;  
    for (i64 i = 0; i < n; i++) {
        c += a[i];
        if (c == rq) ans++;
        ans += f[c - rq];
        f[c]++; 
    }
    return ans; 
}

void compress(vector<long long> &pts) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end()); 
}
long long ID(long long x) {
    return upper_bound(pts.begin(), pts.end(), x) - pts.begin(); 
}

long long Ceil(long long a, long long b) {
    return (a + b - 1) / b; 
}
long long Sigma(long long x) {
    return x * (x + 1) / 2; 
}
long long C2(long long x) {
    return x * (x - 1) / 2; 
}
long long Lcm(long long x, long long y) {
    return x / __gcd(x, y) * y;  
}

bool isPal(string s) {
    int l = 0, r = s.size() - 1;
    while (l <= r and s[l] == s[r]) {
        l++;
        r--;
    } 
    return (l > r); 
}
bool isBal(string s) {
    int c = 0; 
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            c++; 
        } else {
            if (c) {
                c--; 
            } else {
                return false; 
            }
        }
    }
    return (c == 0); 
}
//Using tools : Cout(Bal("(())"), Pal("aabababaa"), Lcm(15, 50), Gcd(10, 85), Ceal(100, 69)); 

// intersect_key 

// point vs line 
bool intersect(int px, int lx, int rx ) {
    return(px >= lx and px <= rx) ; 
}

// segment vs segment (in pair)
// use make_pair while arg or passPair else "passing initialzer list error"
pair<long long, long> intersect2(pair<long long, long long> a, pair<long long, long long> b) {
    long long l[2] = {a.first, a.second}, r[2] = {b.first, b.second};
    pair<long long, long long> pc;
    if (l[0] > r[1] or l[1] < r[0]) {
        pc = {-1ll, -1ll};
    } else {
        pc = {max(l[0], l[1]), min(r[0], r[1])}; 
    }
    return pc; 
}

// make structure instead of pairs then this 
struct seg {
    long long st, en; 
    void show(){
        cout << st << ' ' << en << '\n';
    }
};
bool intersect3(seg s1, seg s2) {
    if (s1.en < s2.st or s2.en < s1.st) {
        return false; 
    } else {
        pair<long long, long long> ans;
        ans = make_pair(max (s1.st, s2.st), min (s1.en, s2.en) ) ;
        return true ; 
    }
}
struct point {
    long long x, y;
};
// x + c%m = x + c, x - (m - c)   

long double CubeRoot(long double u) {
    long double le = 0, ri = 1e6 + 5, crt = 0, md, tmp; 
    for (int i = 0; i < 100; i++) {
        md = (le + ri) / 2; 
        tmp = md * md * md; 
        if (tmp > u) {
            ri = md; 
        } else {
            le = md; 
            crt = md;
        }
    }
    return crt; 
}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
template<typename T = long long>
T Rand(T a, T b) {
    if (a == b) return a;
    if (a > b) swap(a, b);
    return a + (rng() % (b - a + T(1)));
}
int leftIdx(int i, int n) {
    return (i - 1 + n) % n; 
}
int rightIdx(int i, int n) {
    return (i + 1) % n; 
}

n = 7; 
g[1] = {2, 3, 4};
g[2] = {1};
g[3] = {1, 5, 6};
g[4] = {1, 7};
g[5] = {3};
g[6] = {3};
g[7] = {4}; 


n = 6; 
g[1] = {3};
g[2] = {3};
g[3] = {1, 2, 4};
g[4] = {3, 5, 6};
g[5] = {4};
g[6] = {4};  
    
