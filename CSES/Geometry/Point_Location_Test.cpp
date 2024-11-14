#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

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
};

struct line_segment {
    int x1, y1, x2, y2;

    line_segment() : x1(0), y1(0), x2(0), y2(0) {}
    line_segment(int _x1, int _y1, int _x2, int _y2) : x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}
    line_segment(const pair<int, int>& p1, const pair<int, int>& p2) : x1(p1.first), y1(p1.second), x2(p2.first), y2(p2.second) {}
    line_segment(const point& p1, const point& p2) : x1(p1.x), y1(p1.y), x2(p2.x), y2(p2.y) {}
};

struct line {
    int a, b, c;

    line() : a(0), b(0), c(0) {}
    line(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}

    line(int x1, int y1, int x2, int y2){
        int a = y2 - y1;
        int b = x2 - x1;
        int c = x2 * y1 - x1 * y2;
        int gcd = __gcd(__gcd(a, b), c);
        a /= gcd, b /= gcd, c /= gcd;
    }

    line(const pair<int, int>& p1, const pair<int, int>& p2){
        int a = p2.second - p1.second;
        int b = p2.first - p1.first;
        int c = p2.first * p1.second - p1.first * p2.second;
        int gcd = __gcd(__gcd(a, b), c);
        a /= gcd, b /= gcd, c /= gcd;
    }

    line(const point& p1, const point& p2){
        int a = p2.y - p1.y;
        int b = p2.x - p1.x;
        int c = p2.x * p1.y - p1.x * p2.y;
        int gcd = __gcd(__gcd(a, b), c);
        a /= gcd, b /= gcd, c /= gcd;
    }

    line(const line_segment& ls){
        int a = ls.y2 - ls.y1;
        int b = ls.x2 - ls.x1;
        int c = ls.x2 * ls.y1 - ls.x1 * ls.y2;
        int gcd = __gcd(__gcd(a, b), c);
        a /= gcd, b /= gcd, c /= gcd;
    }
};

void solve(){
    line_segment seg;
    point p;
    cin >> seg.x1 >> seg.y1 >> seg.x2 >> seg.y2 >> p.x >> p.y;

    pair<int, int> v1 = {p.x - seg.x1, p.y - seg.y1};
    pair<int, int> v2 = {p.x - seg.x2, p.y - seg.y2};
    int dot = v1.fi * v2.se - v1.se * v2.fi;
    if (dot == 0){
        cout << "TOUCH\n";
    } else if (dot > 0){
        cout << "LEFT\n";
    } else {
        cout << "RIGHT\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}