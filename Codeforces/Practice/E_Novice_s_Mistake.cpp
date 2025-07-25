#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    string ns = to_string(n);
    int len = ns.length();

    if (n == 1){
        cout << 9999 << '\n';
        for (int i = 2; i <= 10000; i++){
            cout << i << ' ' << i - 1 << '\n';
        }
        return;
    }

    vector<pair<int, int>> vans;
    string targets = "";
    for (int i = 0; ; i++){
        targets += ns[i % len];
        cerr << targets << '\n';
        int target = stoi(targets);

        if (target - targets.size() > 10000ll * (n - len)){ // a is too big
            break;
        }

        if ((target - targets.size()) % (n - len) != 0){ // a is not an integer
            continue;
        }

        int a = (target - targets.size()) / (n - len);
        int b = n * a - target;

        if (1 <= a && a <= 10000 && 1 <= b && b <= min(10000ll, a * n)){
            vans.push_back({a, b});
        }
        /*
        len * a - b = targets.size()...(1)
        n * a - b = target...(2)
        b = n * a - target...(2)
        substitute (2) into (1)
        len * a - (n * a - target) = targets.size()...(3)
        (len - n) * a + target = targets.size()...(3)
        a = (targets.size() - target) / (len - n)...(3)
        a = (target - targets.size()) / (n - len)...(3)
        */
    }

    cout << vans.size() << '\n';
    for (int i = 0; i < vans.size(); i++){
        cout << vans[i].fi << ' ' << vans[i].se << '\n';
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