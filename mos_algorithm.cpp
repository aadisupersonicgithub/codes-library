
const int BOX = 1069;  
struct query {
    int le, ri, id;
    bool operator < (query q) {
        int blk1 = le / BOX, blk2 = q.le / BOX;
        if (blk1 != blk2) {
            return blk1 < blk2; 
        } else {
            if (blk1 & 1) {
                return ri < q.ri;
            } else {
                return ri > q.ri;
            }
        }    
    }
};
bool ok(int me) {
    return (me >= 0 and me <= MAXN);
}


// for distinct elements 
int freq[MAXN], a[MAXN], n; 
int Distinct = 0;
void add(int me) {
    if (not ok(me)) {
        return;
    }
    ++freq[a[me]];
    if (freq[a[me]] == 1) {
        ++Distinct;
    }
}
void remove(int me) {
    if (not ok(me)) {
        return;
    }
    if (freq[a[me]] > 0) {
        --freq[a[me]];
        if (freq[a[me]] == 0) {
            --Distinct;
        }
    }        
}

// for most frequent frequency 
int freq[10 * MAXN], cfr[MAXN], a[MAXN], n; 
int mx = 0;
void add(int me) {
    if (not ok(me)) {
        return;
    }
    int val = a[me];
    --cfr[freq[val]];
    if (cfr[freq[val]] == 0) {
        if (mx == freq[val]) {
            --mx;
        }
    }
    ++freq[val];
    mx = max(mx, freq[val]);
    ++cfr[freq[val]];
}
void remove(int me) {
    if (not ok(me)) {
        return;
    }
    int val = a[me];
    --cfr[freq[val]];
    if (cfr[freq[val]] == 0) {
        if (mx == freq[val]) {
            --mx;
        }
    }
    --freq[val];
    mx = max(mx, freq[val]);
    ++cfr[freq[val]];
}

void MOS() 
{   
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int q;
    cin >> q;
    vector<query> Q(q);
    for (int i = 0; i < q; ++i) {
        cin >> Q[i].le >> Q[i].ri;
        --Q[i].le;
        --Q[i].ri;
        Q[i].id = i;
    }
    sort(Q.begin(), Q.end());
    vector<int> ans(q);          
    int pl = 0, pr = 0; 
    for (int i = 0; i < q; ++i) {
        int cl = Q[i].le, cr = Q[i].ri, who = Q[i].id; 
        while (pr <= cr) {
            add(pr);
            ++pr;
        }
        while (pr - 1 > cr) {
            remove(pr - 1);
            --pr;
        }        
        while (pl - 1 >= cl) {
            add(pl - 1);
            --pl;
        }
        while (pl < cl) {
            remove(pl);
            ++pl;
        }
        ans[who] = 1;
    }
    for (int i : ans) cout << i << '\n';
}
