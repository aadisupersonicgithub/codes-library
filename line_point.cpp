struct Point {
    i64 x, y; 
    void get() {
        cin >> x >> y;
    }
    void show() {
        cout << x << ' ' << y << '\n'; 
    }
}; 
struct Line {
    i64 a, b, c; 
    Line() : a(0), b(0), c(0) {
    }
    void show() {
        cout << a << "x + " << b << "y + " << c << " = 0\n"; 
    }
    void init(Point p1, Point p2) {
        a = p2.y - p1.y;
        b = p1.x - p2.x; 
        c = p1.y * p2.x - p1.x * p2.y; 
    }
    bool onit(Point p) {
        return (a * p.x + b * p.y + c == 0);  
    }
    bool side(Point p) {
        return (a * p.x + b * p.y + c > 0); 
    }

};
