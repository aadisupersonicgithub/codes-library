const long double pi = acos(-1.0), inf = 3e18;
void rotate(long double& x2, long double& y2, long double& x1, long double& y1, long double dis, long double ang) {
        x2 = x1 + dis * cos(ang);
        y2 = y1 + dis * sin(ang);
}
long double Angle(long double x1, long double y1, long double x2, long double y2) {
    if (x1 - x2 == 0) {
        return pi / 2; 
    }
    return atan2(y2 - y1, x2 - x1); // return atan((y1 - y2) / (x1 - x2)) ;
}
bool onCircle(long double x, long double y, long long a) {
    return (x * x + y * y) == a * a; 
} 
bool isInt(long double x, long double y) {
    return (x == floor(x) and y == floor(y)); 
}
int quadrant(long double x, long double y) {
    pair<long long, long long> sign = {(x >= 0 ? 1 : -1), (y >= 0 ? 1 : -1)};
    if (sign.first == 1 and sign.second == 1) return 1;
    if (sign.first == -1 and sign.second == 1) return 2;
    if (sign.first == -1 and sign.second == -1) return 3;
    if (sign.first == 1 and sign.second == -1) return 4; 
}
long double polygonArea(long double X[], long double Y[], long long n) {
    long double area = 0.0;
    long long j = n - 1;
    for (long long i = 0; i < n; ++i) {
        area +=(X[j] + X[i]) *(Y[j] - Y[i]);
        j = i; 
    }
    return abs(area / 2.0);
}
long long Sign(long long x) {
    return ((x >= 0) ? 1 : -1); 
}
class Point { 
public:
    long long x, y, z; 
    Point(long long x2 = 0, long long y2 = 0, long long z2 = 0) {
        x = x2;  
        y = y2;
        z = z2;
    } 
    void Show(Point p) {
        cout << "(" << p.x << ", " << p.y << ") " << '\n';
    }
    void Show2() {
        cout << "(" << x << ", " << y << ") " << '\n';
    }
    long double Dist(Point p1, Point p2) {
        long long dx = p2.x - p1.x, dy = p2.y - p1.y, dz = p2.z - p1.z;
        return sqrt(dx * dx + dy * dy + dz * dz);
    } 
    long double Slope(Point p1, Point p2) {
        if (p1.x == p2.x) {
            return pi / 2;
        } else {
            return(p2.y - p1.y) /(p2.x - p1.x);
        }
    }
};
class Vector { 
public:
    long long x, y, z; 
    Vector () { 
        x = y = z = 0;
    } 
    Vector(Point p1, Point p2) {
        x = p2.x - p1.x;
        y = p2.y - p1.y;
        z = p2.z - p1.z;
    } 
    void Show2() {
        cout << " [ " << x << " i + " << y << " j + " << + z << " k " << " ] " << '\n';
    }
    void Show(Vector v) {
        cout << " [ " << v.x << " i + " << v.y << " j + " << + v.z << " k " << " ] " << '\n';
    }
    long double Mod(Vector v) {
        return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    } 
    long long Dot(Vector v1, Vector v2) {
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    } 
    Vector Cross(Vector v1, Vector v2) {
        Vector v3;
        v3.x = +(v1.y * v2.z - v2.y * v1.z);
        v3.y = -(v1.x * v2.z - v2.x * v1.z);
        v3.z = +(v1.x * v2.y - v2.x * v1.y); 
        return v3;
    }
    long double Angle(Vector v1, Vector v2) {
        long double cos_ang = Dot(v1, v2) / (Mod(v1) * Mod(v2));
        return acos(cos_ang);
    } 
    long double Angle2(Vector v1, Vector v2) {
        Vector v3 = Cross(v1, v2);
        long double sin_ang = Mod (v3) / (Mod(v1) * Mod(v2));
        return asin(sin_ang);
    }
};

class Line { 
public:
    long long a, b, c; // ax + by + c = 0;
    Line() {
        a = b = c = 0;
    } 
    Line(Point p1, Point p2) {
        long long x1 = p1.x, y1 = p1.y, x2 = p2.x, y2 = p2.y;
        a = y2 - y1;
        b = x1 - x2;
        c = y1 * x2 - x1 * y2;
    } 
    void Show2() {
        cout << a << " x + " << b << " y + " << c << " = 0 " << '\n';
    }
    void Show(Line l) {
        cout << l.a << " x + " << l.b << " y + " << l.c << " = 0 " << '\n';
    }
    Point Intersection(Line l1, Line l2) {
        long long a1 = l1.a, b1 = l1.b, c1 = l1.c;
        long long a2 = l2.a, b2 = l2.b, c2 = l2.c;
        Point p;
        long long den = a2 * b1 - a1 * b2;
        if (den == 0) {
            p.x = p.y = inf; // parallel ie intersect at infinite 
        } else {
            p.x = (c1 * b2 - c2 * b1) / den; 
            p.y = (a1 * c2 - a2 * c1) / den; 
        }
        return p;
    }
};

struct rect {
    i64 x1, y1, x2, y2;
    void get() {
        cin >> x1 >> y1 >> x2 >> y2;
    }
    void show() {
        cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
    }
    i64 area() {
        return abs((x2 - x1) * (y2 - y1));
    }
};
void swaps(rect& r1, rect &r2) {
    swap(r1.x1, r2.x1);
    swap(r1.x2, r2.x2);
    swap(r1.y1, r2.y1);
    swap(r1.y2, r2.y2);
}
rect common(rect r1, rect r2) {
    if (r1.x1 > r2.x1) {
        swaps(r1, r2);
    }
    i64 t1 = max(r1.x1, r2.x1), t2 = min(r1.x2, r2.x2);
    i64 s1 = max(r1.y1, r2.y1), s2 = min(r1.y2, r2.y2);
    if (t1 > t2 or s1 > s2) {
        return rect{0, 0, 0, 0};
    } else {
        return rect{t1, s1, t2, s2};
    }
}
