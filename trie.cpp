 /*
    trie : 
    applications 
        autocomplete 
        spellchecker 
        longest prefix matching 
        sttring search in o(l) time : l is length of string to be searched 

    k-n ary tree , k=2-> binary k=3->ternary 
    k dpeneds upon size of charcter set to be inserted 
*/
const int MAXK = 26;  
class Trie {  
public:
    Trie *child[MAXK]; 
    int ct; 
    Trie() {
        for (int i = 0; i < MAXK; ++i) {
            child[i] = NULL; 
        }
        ct = 0; 
    }
}; 

void xinsert(Trie *tr, string s) {
    Trie* tmp = tr; 
    int id = 0, u = s[id] - 'a'; 
    while (id < s.size() and tmp->child[u] != NULL) {
        tmp = tmp->child[u];
        ++id; 
        u = s[id] - 'a'; 
    }    
    while (id < s.size()) {
        int ci = s[id] - 'a'; 
        Trie *t1 = new Trie(); 
        tmp->child[ci] =  t1; 
        tmp = tmp->child[ci]; 
        ++id; 
    }
    ++tmp->ct; 
}
int xsearch(Trie *tr, string s) {
    Trie *tmp = tr; 
    int id = 0, ci = s[id] - 'a'; 
    while (id < s.size() and tmp->child[ci] != NULL) {
        tmp = tmp->child[ci];
        ++id; 
        if (id < s.size()) {
            ci = s[id] - 'a'; 
        } else {
            return tmp->ct; 
        }
    }
    return 0;
}
void xdelete(Trie *tr, string s) {
    Trie *tmp = tr;
    int id = 0, k = s[id] - 'a';
    while (id < s.size()) {
        if (tmp->child[k] == NULL) {
            return;
        }
        tmp = tmp->child[k];
        ++id;
        if (id < s.size()) {
            k = s[id] - 'a'; 
        }
    }
    if (tmp->ct) {
        --tmp->ct; 
    }
}

void winsert(Trie *tr, string s) {
    Trie *tmp = tr;
    for (int i = 0; i < s.size(); ++i) {
        int id = s[i] - 'a';
        if (tmp->child[id] == NULL) {
            tmp->child[id] = new Trie();
        }
        tmp = tmp->child[id]; 
    }
    ++tmp->ct;
}
int wsearch(Trie *tr, string s) {
    Trie *tmp = tr; 
    for (int i = 0; i < s.size(); ++i) {
        int id = s[i] - 'a'; 
        if (tmp->child[id] == NULL) {
            return 0; 
        }
        tmp = tmp->child[id];
    }
    return tmp->ct; 
}
void wdelete(Trie *tr, string s) {
    Trie *tmp = tr;
    for (int i = 0; i < s.size(); ++i) {
        int id = s[i] - 'a'; 
        if (tmp->child[id] == NULL) {
            return; 
        }
        tmp = tmp->child[id];
    }
    if (tmp->ct) {
        --tmp->ct; 
    }
}

void Solution() 
{
    vector<string> f = {"bad", "back", "car", "cat", "honey"}; 
    Trie *H = new Trie(); 
    for (auto i : f) {
        xinsert(H, i);   
    }
    if (xsearch(H, "bad")) {
        cout << "bad hai"; 
        if (xsearch(H, "back")) {
            cout << "back hai";
            if (xsearch(H, "car")) {
                cout << "car hai"; 
                if (xsearch(H, "cat")) {
                    cout << "cat hai";
                    if (xsearch(H, "honey")) {
                        cout << "honey hai"; 
                    }
                }
            }  
        }
    } else {
        cout << "not working"; 
    }
    xdelete(H, "honey");
    if (!xsearch(H, "honey")) {
        cout << "ab honey nahi hai"; 
    }
}
