#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m; cin >> n >> m;
    vector<int> l(m + 1), r(m + 1);
    for (int i = 1; i <= m; i++){
        cin >> l[i] >> r[i];
    }

    vector<int> pref(n + 2);
    for (int i = 1; i <= m; i++){
        pref[l[i]]++;
        pref[r[i] + 1]--;
    }

    // priority 1
    {
        vector<int> vans(n);
        iota(vans.begin(), vans.end(), 0);
        for (int i = 1; i <= n; i++){
            pref[i] += pref[i - 1];
            if (pref[i] == m){
                swap(vans[0], vans[i - 1]);
                for (int i = 0; i < n; i++){
                    cout << vans[i] << " \n"[i == n - 1];
                }
                return;
            }
        }
    }
    // priority 2
    {
        vector<int> vans(n);
        iota(vans.begin(), vans.end(), 0);
        for (int i = 1; i <= n; i++){
            pref[i] += pref[i - 1];
            if (pref[i] == 0){
                swap(vans[0], vans[i - 1]);
                for (int i = 0; i < n; i++){
                    cout << vans[i] << " \n"[i == n - 1];
                }
                return;
            }
        }
    }
    // priority 3
    {
        vector<int> vans(n);
        iota(vans.begin(), vans.end(), 0);
        for (int i = 1; i <= n - 1; i++){
            bool ok = true;
            for (int j = 1; j <= m; j++){
                if (!(l[j] > i || r[j] < i || l[j] <= i && i + 1 <= r[j])){
                    ok = false;
                    break;
                }
            }
            if (ok){
                swap(vans[1], vans[i]);
                swap(vans[0], vans[i - 1]);
                for (int i = 0; i < n; i++){
                    cout << vans[i] << " \n"[i == n - 1];
                }
                return;
            }
        }
        for (int i = 1; i <= n - 1; i++){
            bool ok = true;
            for (int j = 1; j <= m; j++){
                if (!(l[j] > i + 1 || r[j] < i + 1 || l[j] <= i && i + 1 <= r[j])){
                    ok = false;
                    break;
                }
            }
            if (ok){
                swap(vans[0], vans[1]);
                swap(vans[1], vans[i]);
                swap(vans[0], vans[i - 1]);
                for (int i = 0; i < n; i++){
                    cout << vans[i] << " \n"[i == n - 1];
                }
                return;
            }
        }
    }
    // priority 4
    {
        vector<int> vans(n);
        iota(vans.begin(), vans.end(), 0);
        swap(vans[1], vans[n - 1]);
        for (int i = 0; i < n; i++){
            cout << vans[i] << " \n"[i == n - 1];
        }
    }

    /*
    priority 1: 0 in all, ans is 0
    priority 2: 0 in none, ans is 1
    priority 3: whatever segment 0 is in, also include 1, ans is 1
    priority 4: place 0 at index 1, place 1 at index n
        case 1: segment [1, n] does not exist, mex of only 0 and 1 exist, ans is 2
        case 2: segment [1, n] does exist, said segment will not have a mex of 2, but rather n, ans is 2
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