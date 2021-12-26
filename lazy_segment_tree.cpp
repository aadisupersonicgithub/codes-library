
#include <bits/stdc++.h>
using namespace std;   
typedef long long i64; 
#define Savitar ios::sync_with_stdio(0); cin.tie(0); 

const long N = 1e5 + 5; 
const long inf = INT_MAX;
struct Node {
    long sm, mn, mx; 
    Node() {
        sm = 0, mn = inf, mx = -inf;
    }
}; 

i64 a[N]; 
Node tr[4 * N], avoid;
long lz[4 * N]; 
long n; 
template<typename T> vector<T> merger(vector<T> v1, vector<T> v2) {
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
Node merge(Node n1, Node n2) {
    Node n3;
    
    return n3; 
}
void buildx(long si, long ss, long se) {
    if (ss == se) {
        // set leaf condition 
        // tr[si].el.push_back(a[ss]); 
        tr[si].sm = a[ss]; 
        return; 
    }
    long md = (ss + se) / 2;
    buildx(2 * si, ss, md);
    buildx(2 * si + 1, md + 1, se);
    tr[si] = merge(tr[si * 2], tr[si * 2 + 1]);
}

void relax(long si, long ss, long se) {
    if (lz[si]) {
        // do tr[c] updation ... 
        // tr[c] += (se - ss + 1) * lz[si]; // in sum
        if (ss != se) {
            lz[2 * si] += lz[si];
            lz[2 * si + 1] += lz[si]; 
        }
        lz[si] = 0; 
    }
}
Node rqryx(long si, long ss, long se, long ql, long qr) {
    relax(si, ss, se);
    if(ql > se or qr < ss) {
        return avoid;
    }
    if (ql <= ss and se <= qr) {
        return tr[si];
    }
    else {
        long md = (ss + se) / 2;
        Node le = rqryx(2 * si, ss, md, ql, qr);
        Node ri = rqryx(2 * si + 1, md + 1, se, ql, qr); 
        return merge(le, ri); 
    }
}
Node rqry(long ql, long qr) {
    return rqryx(1, 1, n, ql, qr); 
}
void build() {
    buildx(1, 1, n); 
}

void rupdx(long si, long ss, long se, long ql, long qr, long val) {
    relax(si, ss, se);
    if (qr < ss or ql > se) {
        return;
    }
    if (ql <= ss and se <= qr) {
        tr[si].sm += (se - ss + 1) * val; 
        if (ss != se) {
            lz[2 * si] += val; 
            lz[2 * si + 1] += val; 
        }
    } else {
        long md = (ss + se) / 2;
        rupdx(2 * si, ss, md, ql, qr, val);
        rupdx(2 * si + 1, md + 1, se, ql, qr, val);
        tr[si] = merge(tr[2 * si], tr[2 * si + 1]); 
    }
}

void rupd(long ql, long qr, long val) {
    rupdx(1, 1, n, ql, qr, val); 
}
long find_kth(long v, long ss, long se, long k) {
    if (k > tr[v].sm)
        return -1l;
    if (ss == se)
        return ss;
    long tm = (ss + se) / 2;
    if (tr[v*2].sm >= k)
        return find_kth(v*2, ss, tm, k);
    else 
        return find_kth(v*2+1, tm+1, se, k - tr[v*2].sm);
}
void init() {
  
}

void go()
{

}
signed main ()
{
     
    Savitar; 
    #ifndef LOCAL
        freopen("dbg_i1.txt", "r", stdin);
        // freopen("dbg_o1.txt", "w", stdout);
        freopen("dbg_e1.txt", "w", stderr); 
    #endif
    long tt = 1;
    cin >> tt; 
    for (long c = 1; c <= tt; c++) {
        cerr << "Case #" << c << ":\n";
        go();
    }
    return 0;
}
