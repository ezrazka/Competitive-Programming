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
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j){
        return v[i] < v[j];
    });

    if (v[ord[0]] == 0 && v[ord[n - 1]] == n){
        cout << "NO\n";
        return;
    }

    vector<int> vans(n);
    bool ok = true;
    for (int i = n - 1; i >= 0; i--){
        if (v[ord[i]] < n - i){
            for (int j = 0; j <= i; j++){
                if (v[ord[j]] == 0){
                    vans[ord[j]] = -n;
                    continue;
                }
                int cutoff = n - v[ord[j]];
                if (v[ord[cutoff - 1]] == v[ord[cutoff]]){
                    ok = false;
                    break;
                } else {
                    vans[ord[j]] = -(vans[ord[cutoff]] - 1);
                }
            }
            for (int j = i + 1; j < n; j++){
                int l = 0, r = n - 1, res = n;
                while (l <= r){
                    int mid = (l + r) / 2;
                    if (vans[ord[mid]] <= -vans[ord[j]]){
                        l = mid + 1;
                        res = (n - 1) - mid;
                    } else {
                        r = mid - 1;
                    }
                }
                if (v[ord[j]] != res){
                    ok = false;
                    break;
                }
            }
            break;
        }
        if (i == n - 1){
            vans[ord[i]] = n - (v[ord[0]] == 0);
        } else if (v[ord[i]] == v[ord[i + 1]]){
            vans[ord[i]] = vans[ord[i + 1]];
        } else {
            vans[ord[i]] = vans[ord[i + 1]] - 2;
        }
    }

    if (ok){
        cout << "YES\n";
        for (int i = 0; i < n; i++){
            cout << vans[i] <<  " \n"[i == n - 1];
        }
    } else {
        cout << "NO\n";
    }

    /*
    assuming a is sorted,
    we can see that b is monotonically increasing
    the first positive number is where a[i] = n + 1 - i (if it exists)
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}