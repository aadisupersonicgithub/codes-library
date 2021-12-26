const int MAXK = 19;  
int nV, nE, Timer, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}, dz[3] = {-1, 0, 1}; 
vector<int> adj[MAXN], lit(MAXN), par(MAXN), dist(MAXN), col(MAXN), sz(MAXN, 1), leafs, tin(MAXN), tout(MAXN), ele; 

void dfs(int s) {
    tin[s] = ++Timer; 
    lit[s] = 1;
    bool leaf = true;  
    for (auto v : adj[s]) {
        if (!lit[v]) {
            dist[v] = dist[s] + 1; 
            par[v] = s; 
            dfs(v); 
            sz[s] += sz[v]; 
            leaf = false; 
        }
    }
    if (leaf) {
        leafs.push_back(s);  
    }
    ele.push_back(s); 
    tout[s] = ++Timer; 
    lit[s] = false; 
}

bool isAncestor(int u, int v) {
    return (tin[u] <= tin[v] and tout[v] <= tout[u]); 
}

bool isLeaf(int s) {
    return (adj[s].size() == 1);
}

void iEdge() { 
    int fr, to; 
    cin >> fr >> to; 
    adj[fr].push_back(to); 
    adj[to].push_back(fr); 
}

void iShow() { 
    for (int i = 1; i <= nV; i++) { 
        if (adj[i].size()) { 
            cout << i << "->"; 
            for (auto j : adj[i])  {
                cout << j << ' '; 
            }
            cout << '\n'; 
        }
    }
}

void iClear() {
    for (int i = 1; i <= nV; ++i) {
        adj[i].clear();
    }
}
