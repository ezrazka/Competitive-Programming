#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const ld PI = acos((ld) -1);

void solve(){
    int n, r; cin >> n >> r;

    auto get_point = [&](int i){
        return make_pair(cos(2 * PI * i / n + 42), sin(2 * PI * i / n + 42));
    };
    pair<ld, ld> p1 = get_point(0);
    pair<ld, ld> p2 = get_point(n / 2);
    pair<ld, ld> p3 = get_point(1);
    pair<ld, ld> p4 = get_point(1 - n / 2);
    pair<ld, ld> line1;
    {
        line1.first = (p2.second - p1.second) / (p2.first - p1.first);
        line1.second = p1.second - line1.first * p1.first;
    }
    pair<ld, ld> line2;
    {
        line2.first = (p4.second - p3.second) / (p4.first - p3.first);
        line2.second = p3.second - line2.first * p3.first;
    }
    pair<ld, ld> p5;
    {
        p5.first = (line2.second - line1.second) / (line1.first - line2.first);
        p5.second = line1.first * p5.first + line1.second;
    }

    ld inscribed_polygon = (ld) n * sin(2 * PI / n) / 2;
    ld triangle = 0.5 * abs(
        (p1.first * p3.second + p3.first * p5.second + p5.first * p1.second) -
        ((p1.second * p3.first + p3.second * p5.first + p5.second * p1.first))
    );
    ld ans = inscribed_polygon * r * r - n * triangle * r * r;

    cout << fixed << setprecision(9) << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}