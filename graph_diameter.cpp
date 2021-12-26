int dia_st = -1, dia_en = -1, st_d = -1, en_d = -1; 
void dfs1(int s, int d = 0, int p = -1) {
    if (d > st_d) {
        st_d = d; 
        dia_st = s; 
    }
    for (auto v : g[s]) {
        if (v != p) {
            dfs1(v, d + 1, s); 
        }
    }
}
void dfs2(int s, int d = 0, int p = -1) {
    if (d > en_d) {
        en_d = d; 
        dia_en = s; 
    }
    for (auto v : g[s]) {
        if (v != p) {
            dfs2(v, d + 1, s);
        }
    }
}
void get_dia() {
    dfs1(1);
    dfs2(dia_st);
}
