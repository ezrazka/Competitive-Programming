#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

int sign(int a){
    if (a == 0) return 0;
    if (a < 0) return -1;
    return 1;
}

int dot(int x1, int y1, int x2, int y2){
    return x1 * y2 - x2 * y1;
}

struct point {
    int x, y;

    point() : x(0), y(0) {}
    point(int _x, int _y) : x(_x), y(_y) {}
    point(const pair<int, int>& p) : x(p.first), y(p.second) {}

    bool operator<(const point& other) const {
        return make_pair(x, y) < make_pair(other.x, other.y);
    }

    bool operator>(const point& other) const {
        return make_pair(x, y) > make_pair(other.x, other.y);
    }

    bool operator==(const point& other) const {
        return make_pair(x, y) == make_pair(other.x, other.y);
    }
};

struct line_segment {
    int x1, y1, x2, y2;

    line_segment() : x1(0), y1(0), x2(0), y2(0) {}
    line_segment(int _x1, int _y1, int _x2, int _y2) : x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}
    line_segment(const pair<int, int>& p1, const pair<int, int>& p2) : x1(p1.first), y1(p1.second), x2(p2.first), y2(p2.second) {}
    line_segment(const point& p1, const point& p2) : x1(p1.x), y1(p1.y), x2(p2.x), y2(p2.y) {}

    bool intersects(const line_segment& other){
        if (point(x1, y1) == point(other.x1, other.y1)) return true;
        if (point(x1, y1) == point(other.x2, other.y2)) return true;
        if (point(x2, y2) == point(other.x1, other.y1)) return true;
        if (point(x2, y2) == point(other.x2, other.y2)) return true;

        int loc11 = dot(x1 - other.x1, y1 - other.y1, x1 - other.x2, y1 - other.y2);
        int loc12 = dot(x2 - other.x1, y2 - other.y1, x2 - other.x2, y2 - other.y2);
        int loc21 = dot(other.x1 - x1, other.y1 - y1, other.x1 - x2, other.y1 - y2);
        int loc22 = dot(other.x2 - x1, other.y2 - y1, other.x2 - x2, other.y2 - y2);

        if (loc11 == 0 && loc12 == 0 && loc21 == 0 && loc22 == 0){
            if (max(x1, x2) < min(other.x1, other.x2)) return false;
            if (max(other.x1, other.x2) < min(x1, x2)) return false;
            if (max(y1, y2) < min(other.y1, other.y2)) return false;
            if (max(other.y1, other.y2) < min(y1, y2)) return false;
            return true;
        }

        return (sign(loc11) != sign(loc12) && sign(loc21) != sign(loc22));
    }
};

struct line {
    int a, b, c;

    line() : a(0), b(0), c(0) {}
    line(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}

    line(int x1, int y1, int x2, int y2){
        a = y2 - y1;
        b = x2 - x1;
        c = x2 * y1 - x1 * y2;
        int gcd = abs(__gcd(__gcd(a, b), c));
        a /= gcd, b /= gcd, c /= gcd;
    }

    line(const pair<int, int>& p1, const pair<int, int>& p2){
        a = p2.second - p1.second;
        b = p2.first - p1.first;
        c = p2.first * p1.second - p1.first * p2.second;
        int gcd = abs(__gcd(__gcd(a, b), c));
        a /= gcd, b /= gcd, c /= gcd;
    }

    line(const point& p1, const point& p2){
        a = p2.y - p1.y;
        b = p2.x - p1.x;
        c = p2.x * p1.y - p1.x * p2.y;
        int gcd = abs(__gcd(__gcd(a, b), c));
        a /= gcd, b /= gcd, c /= gcd;
    }

    line(const line_segment& ls){
        a = ls.y2 - ls.y1;
        b = ls.x2 - ls.x1;
        c = ls.x2 * ls.y1 - ls.x1 * ls.y2;
        int gcd = abs(__gcd(__gcd(a, b), c));
        a /= gcd, b /= gcd, c /= gcd;
    }
};

void solve(){
    line_segment ls1, ls2;
    cin >> ls1.x1 >> ls1.y1 >> ls1.x2 >> ls1.y2;
    cin >> ls2.x1 >> ls2.y1 >> ls2.x2 >> ls2.y2;
    cout << (ls1.intersects(ls2) ? "YES\n" : "NO\n");
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}