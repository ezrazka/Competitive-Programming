#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

int mod_inv(int a, int m) {
  return a <= 1 ? a : m - (long long)(m/a) * mod_inv(m % a, m) % m;
}

struct Congruence {
    long long a, m;
};

long long chinese_remainder_theorem(vector<Congruence> const& congruences) {
    long long M = 1;
    for (auto const& congruence : congruences) {
        M *= congruence.m;
    }

    long long solution = 0;
    for (auto const& congruence : congruences) {
        long long a_i = congruence.a;
        long long M_i = M / congruence.m;
        long long N_i = mod_inv(M_i, congruence.m);
        solution = (solution + a_i * M_i % M * N_i) % M;
    }
    return solution;
}

void solve(){
    int a, b, x, y; cin >> a >> b >> x >> y;
    if (a > b){
        swap(a, b);
        swap(x, y);
    }

    // x = 0 (mod a)
    // x = -gcd(a, b) (mod b)

    int mn = (a * (x - 1) + gcd(a, b)) / b, mx = (a * (x + 1) - gcd(a, b) + b - 1) / b;
    if (y == mn){
        Congruence aa, bb;
        aa.a = 0, aa.m = a;
        bb.a = a - gcd(a, b), bb.m = b;
        cout << chinese_remainder_theorem({aa, bb}) << ' ' << chinese_remainder_theorem({aa, bb}) + a * (x - 1) + gcd(a, b) - 1 << '\n';
    } else if (y == mx){
        cout << a * b << ' ' << a * b + a * (x + 1) - gcd(a, b) - 1 << '\n';
    } else {
        cout << a * b << ' ' << a * b + a * (x + 1) - gcd(a, b) - 1 - b << '\n';
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