// a + b = a^b + 2*(a&b)

vector<pair<long long, long long>> merge_overlapping(vector<pair<long long, long long>> v) {
  sort(v.begin(), v.end());
  vector<pair<long long, long long>> f;
  f.push_back(v[0]);
  for (int i = 1; i < v.size(); ++i) {
    if (v[i].first <= f.back().second) {
      f.back().second = v[i].second;
    } else {
      f.push_back(v[i]);
    }
  }
  return f;
}

stack<pair<long long, long long>> merge_overlapping(vector<pair<long long, long long>> v) {
  sort(v.begin(), v.end());
  stack<pair<long long, long long>> f;
  f.push(v[0]);
  for (int i = 1; i < v.size(); ++i) {
    if (v[i].first <= f.top().second) {
      f.top().second = v[i].second;
    } else {
      f.push(v[i]);
    }
  }
  return f;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x, int y) { return (rng() % (y - x +1)) + x;};

map<char, int> CI;
map<int, char> IC;

long long tw[MAXN], ten[MAXN]; 

void tools_init() {
  int ct = 0; 
  for (char c = 'a'; c <= 'z'; c++) {
    int x = c - 'a' + 1;
    CI[c] = x ; 
    IC[x] = c; 
  }
  for (char c = 'A'; c <= 'Z' ; c++) {
    int x = c - 'A' + 1 + 26;
    CI[c] = x ; 
    IC[x] = c; 
  }
  tw[0] = ten[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    tw[i] = Mul(tw[i - 1], 2); 
    ten[i] = Mul(ten[i - 1], 10); 
  }
}

map<long long, long long> fr, ba;
void Compress(vector<long long> &pts) {
  sort(pts.begin(), pts.end()); 
  pts.erase(unique(pts.begin(), pts.end()), pts.end()); 
  long long ctr = 1; 
  for (auto i : pts) {
    fr[i] = ctr;
    ba[c] = i;
    ++ctr;  
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

bool isPalindrome(string s) {
  int l = 0, r = s.size() - 1;
  while (l <= r and s[l] == s[r]) {
    l++;
    r--;
  } 
  return (l > r); 
}
bool isPrime(long long x) {
  for (i64 i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      return true;
    }
  }
  return false;
}
bool isBalanced(string s) {
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
vector<vector<char>> rotate(vector<vector<char>> f) {
  int n = f.size();
  vector<vector<char>> fr = f;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      fr[j][n - 1 - i] = f[i][j];
    }
  }
  return fr;
}
bool compare(vector<vector<char>> f1, vector<vector<char>> f2) {
  bool ex = true;
  int n = f1.size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ex &= (f1[i][j] == f2[i][j]);
    }
  }
  return ex;
}
vector<vector<char>> flip1(vector<vector<char>> f) {
  auto flip = f;
  int n = f.size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      flip[i][j] = f[n - 1 - i][j];
    }
  }
  return flip;
}
vector<vector<char>> flip2(vector<vector<char>> f) {
  auto flip = f;
  int n = f.size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      flip[i][j] = flip[i][n - 1 - j];
    }
  }
  return flip;
}
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
int f[26][MAXN];
i64 qry(int x, int le, int ri) {
  return f[x][ri] - (le ? f[x][le - 1] : 0LL); 
}
for (int i = 0; i < n; i++) {
  f[s[i] - 'a'][i]++; 
}
for (int j = 0; j < 26; j++) {
  for (int i = 1; i < n; i++) {
    f[j][i] += f[j][i - 1]; 
  }
}

struct node{
  i64 ht, wd, id; 
  void get() {
    cin >> ht >> wd; 
    if (ht > wd) {
      swap(ht, wd); 
    }
  }
  void show() {
    cout << ht << ' ' << wd << ' '  << id << '\n'; 
  }
};
struct cmpx {
  inline bool operator() (const node& n1, const node& n2) {
    if (n1.ht != n2.ht) {
      return n1.ht < n2.ht;
    } else if (n1.wd != n2.wd) {
      return n1.wd < n2.wd; 
    } else {
      return n1.id < n2.id; 
    }
  }
}; 

long long n, ar[MAXN], dp[MAXN]; 
long long kadane() {
    long long mx = -1e18, cur = 0;
    for (long long i = 0; i < n; ++i) {
        cur = max(cur + ar[i], ar[i]);
        mx = max(mx, cur); 
    }
    return mx; 
}
p
vector<i64> a(n), pre(n), suf(n); 
for (int i = 0; i < n; i++) {
    cin >> a[i]; 
    pre[i] = a[i]; 
    suf[i] = a[i]; 
    if (i) pre[i] += pre[i - 1]; 
}
for (int i = n - 2; i >= 0; i--) {
    suf[i] += suf[i + 1]; 
}
auto stx = [&] (int x) {
    return (x ? pre[x - 1] : 0LL); 
}; 
auto enx = [&] (int x) {
    return ((x == 0) ? 0 : suf[n - x]); 
};

template<typename T>  
void subseq(vector<T> a, int id, vector<T> b) {
  if (id == a.size()) {
    dbg("b : ", b);  
  } else {        
    subseq(a, id + 1, b); 
    b.push_back(a[id]); 
    subseq(a, id + 1, b); 
  }
}
void permute(string str, int l, int r) {
  if (l == r) {
      dbg("str : ", str);  
  } else {
    for(int i = l; i <=r; i++) {
      swap(str[i], str[l]);
      permute2(str, l + 1, r);
      swap(str[i], str[l]);
    }   
  }
}

template<typename T> 
vector<T> merger(vector<T> v1, vector<T> v2) {
    int n1 = v1.size(), n2 = v2.size(); 
    int n3 = n1 + n2; 
    vector<T> v3(n3); 
    int ptr1 = 0, ptr2 = 0, ptr3 = 0;
    while (ptr1 < n1 and ptr2 < n2) {
        if (v1[ptr1] <= v2[ptr2]) {
            v3[ptr3++] = v1[ptr1++]; 
        } else {
            v3[ptr3++] = v2[ptr2++]; 
        }
    }
    while (ptr1 < n1) {
        v3[ptr3++] = v1[ptr1++]; 
    }
    while (ptr2 < n2) {
        v3[ptr3++] = v2[ptr2++]; 
    }
    return v3; 
}

auto angle = [&] (int xi, int yi) {
        long double u; 
        if (yi == 0 and xi > 0) {
            u = 0.0;
        }
        else if (xi > 0 and yi > 0) {
            u = atan(yi * 1.0 / xi);
        }
        else if (xi == 0 and yi > 0) {
            u = pi / 2.0;
        }
        else if (xi < 0 and yi > 0) {
            u = atan(yi * 1.0 / abs(xi));
        }
        else if (yi == 0 and xi < 0) {
            u = pi;
        }
        else if (xi < 0 and yi < 0) {
            u = pi + atan(abs(yi) * 1.0 / abs(xi));
        }
        else if (xi == 0 and yi < 0) {
            u = 3 * pi / 2.0;
        }
        else if (xi < 0 and yi < 0) {
            u = 2 * pi - atan(abs(yi) * 1.0 / abs(xi));
        }
        return u;
     };

clock_t START;
long double TIME() {
    return (long double) (clock() - START) / CLOCKS_PER_SEC;
} 
void SHOW() {
    cout << fixed << setprecision(10);
    cout << TIME() << "s.\n";
}

i64 H;
long long node_height(long long x) {
  return log2(x) + 1;
}
long long totalNodesInSubtree(long long x) {
  long long u = node_height(x);
  long long total = bitVal(H - u + 1) - 1; 
}
long long eachChildSize(long long x) {
  long long u = node_height(x);
  long long child_size = bitVal(H - u) - 1;
}
long long sibling(long long x) {
  if (x & 1) {
    --x;
  } else {
    ++x;
  }
  return x;
}
//            1 [H = 1]
//     2          3
//  4    5     6     7
// 8 9 10 11 12 13 14 15 [H = 4]
// perfect BT ie 2 * child_size + 1 = totalNodesInSubstree 
