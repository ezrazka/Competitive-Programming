#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int x, int y){
  return uniform_int_distribution<int>(x, y)(rng);
}

int query1(int i){
    cout << "? " << i + 1 << endl;
    int x; cin >> x;
    return x;
}

int query2(int n){
    cout << "> " << n << endl;
    int x; cin >> x;
    return x;
}

void answer(int a, int d){
    cout << "! " << a << ' ' << d << endl;
}

void solve(){
    int n; cin >> n;
    
    int l = 0, r = 1e9, x_n;
    while (l <= r){
        int mid = (l + r) / 2;
        
        int q = query2(mid);
        
        if (q){
            l = mid + 1;
        } else {
            r = mid - 1;
            x_n = mid;
        }
    }
    
    vector<bool> checked(n);
    vector<int> v;
    for (int _ = 0; _ < min(n, 30ll); _++){
        int i;
        do {
            i = rnd(0, n - 1);
        } while (checked[i]);
        int q = query1(i);
        v.push_back(q);
        checked[i] = true;
    }

    int d = 0;
    for (int i = 0; i + 1 < v.size(); i++){
        d = __gcd(d, abs(v[i] - v[i + 1]));
    }

    int a = x_n - (n - 1) * d;
    answer(a, d);
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}