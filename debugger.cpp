
void Cout() { 
    cout << " "; 
} 
template <typename T, typename... U> 
void Cout(T var1 , U... var2) { 
    cout << var1 << " "; 
    Cout(var2...); 
} 

void Cin() {} 
template <typename T , typename...Rest> 
void Cin ( T& value , Rest&&...rest) { 
    cin >> value; 
    Cin(forward<Rest>(rest)...); 
}  

template <typename T , typename U> 
istream& operator>>(istream& orz , pair<T, U> &f) { 
    orz >> f.first >> f.second; 
    return orz; 
} 

template <typename T> 
istream& operator>>(istream& orz, vector<T> &f) {  
    for (auto &i : f) {
        orz >> i; 
    }
    return orz; 
}

template <typename T> 
ostream& operator<<(ostream& orz , vector<T> &f) { 
    orz << "{"; 
    for (auto i : f) 
        orz << i << ", "; 
    orz << "} "; 
    return orz; 
} 

template <typename T> 
ostream& operator<<(ostream& orz, set<T> &f) { 
    orz << "{"; 
    for (auto i : f) { 
        orz << i << ", "; 
    } 
    orz << "} "; 
    return orz; 
} 

template <typename T> 
ostream& operator<<(ostream& orz, multiset<T> &f) {
    orz << "{"; 
    for (auto i : f) { 
        orz << i << ", "; 
    } 
    orz << "}"; 
    return orz; 
} 

template <typename T, typename U> 
ostream& operator<<(ostream& orz, map<T, U> &f) { 
    orz << "["; 
    for (auto i : f) {
        orz << "(" << i.first << ", " << i.second << ")"; 
    }
    orz <<"]"; 
    return orz;
} 

template <typename T , typename U> 
ostream& operator<<(ostream& orz, pair<T, U> &f) { 
    orz << "(" << f.first << ", " << f.second << ")" << " "; 
    return orz; 
} 

template <typename T> 
ostream& operator<<(ostream& orz, queue<T> &q) { 
    auto Q = q; 
    orz << "{ ";  
    while (Q.size()) { 
        cout << Q.front() << " "; 
        Q.pop();  
    } 
    orz << " }"; 
    return orz; 
}

template <typename T> 
ostream& operator<<(ostream& orz, stack<T> &s) { 
    auto S = s; 
    orz << "{ ";  
    while (S.size()) { 
        cout << S.top() << " "; 
        S.pop(); 
    }  
    orz << " }"; 
    return orz;
} 

template <typename T , typename U>
void AIP (U a[] , T n) { 
    for (T i = 0; i < n; i++) {
        cin >> a [i]; 
    }
} 
template <typename T, typename U> 
void AOP (U a[] , T n) { 
    cout << "{ "; 
    for (T i = 0; i < n; i++) {
        cout << a [i] << " "; 
    }
    cout << "} "; 
}
