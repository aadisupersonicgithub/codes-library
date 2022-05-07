
template<typename T> 
class DSU { 
public:
    T U; 
    vector<T> p, Sz; 
    DSU() {}
    DSU(T n) : p(n + 1), Sz(n + 1) {
        iota(p.begin(), p.end(), 0);  
        fill(Sz.begin(), Sz.end(), 1);
    }
    T Find(T a) {
        if (a == p[a]) {
            return a; 
        }
        return p[a] = Find(p[a]);
    }
    bool Union(T a, T b) {
        a = Find(a); 
        b = Find(b); 
        if (a != b) {
            if (Sz[a] < Sz[b]) {
                swap(a, b);        
            }
            Sz[a] += Sz[b];
            p[b] = a;
            return true; 
        }
        return false; 
    }
    bool Same(T a, T b) {
        return (Find(a) == Find(b));
    }
    bool Diff(T a, T b) {
        return (Find(a) != Find(b)); 
    }
    set<T> roots; 
    map<T, set<T>> comp; 
    void store() {
        for (T i = 1; i < U; i++) {
            T pr = Find(i);
            roots.insert(pr) ;
            comp[pr].insert(i); 
        }
    }
};
