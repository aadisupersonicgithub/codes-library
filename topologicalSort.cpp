
vector<int> adj[MAXN], pri(MAXN);
vector<bool> vis(MAXN, false);
int p = 1;
void dfs(int u) {
    vis[u] = true;
    for (auto v : adj[u]) {
        if (!vis[v]) {
            dfs(v);    
        }
    }
    pri[u] = p++;
}
int main()  
{
    int n, m;   
    cin >> n >> m;
    for (int i = 0; i < m; ++i)  {
        int x, y;   
        cin >> x >> y;
        adj[x].push_back(y);
    }
    for (int i = 0; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    // for(int i=0; i<=n; i++) cout<<i<<" "<<pri[i]<<"\n";
    vector<int> top_sort(n + 1);
    for (int i = 0; i <= n; ++i) {
        top_sort[i] = i;
    }
    sort(top_sort.begin(), top_sort.end(), [&](int x, int y) { return pri[x] > pri[y];});
    for (auto i: top_sort) cout << i << " ";
}

// bfs 
vector<int> topo;
void topoSort(int x) {    
    int lit2[nV + 1] = {};
    queue<int> Q2; 
    Q2.push(x);
    vector<int> comp;
    while (Q2.size()) {
        auto h = Q2.front();
        lit2[h] = 1; 
        comp.push_back(h);
        Q2.pop(); 
        for (auto v : adj[h]) {
            if (!lit2[v]) {
                Q2.push(v); 
            }
        }
    }
    queue<int> Q; 
    vector<int> dg(nV + 1, 0); 
    for (auto i : comp) {
        for (auto j : adj[i]) {
            ++dg[j];
        }
    }
    for (int i : comp) {
        if (dg[i] == 0) {
            Q.push(i);
        }
    }
    
    while (Q.size()) {
        auto f = Q.front();
        lit[f] = 1;
        Q.pop();
        topo.push_back(f);
        for (auto v : adj[f]) {
            --dg[v];
            if (dg[v] == 0) {
                Q.push(v); 
            }
        }
    }
}
void get_topo() {
    for (int i = 1; i <= nV; ++i) {
        if (!lit[i]) {
            topoSort(i);
        }
    }
}


int nV, nE; 
vector<int> adj[MAXN], par(MAXN), dist(MAXN), lit(MAXN), ord;
void dfs(int s, stack<int> &stk) {
    lit[s] = 1;  
    for (auto v : adj[s]) {
        if (!lit[v]) {
            dfs(v, stk);  
        }
    }
    stk.push(s);  
}
stack<int> topoSort() {
    stack<int> stk; 
    for (int i = 1; i <= nV; ++i) {
        if (!lit[i]) {
            dfs(i, stk); 
        }
    }
    return stk; 
}




void dfs1(int s) {
    lit[s] = 1;
    for (auto v : adj[s]) {
        if (!lit[v]) {
            dfs1(v);    
        }
    }
    topo.push_back(s);
}
for (int i = 1; i <= n; ++i) {
    if (!lit[i]) {
        dfs1(i);      
    }        
}
