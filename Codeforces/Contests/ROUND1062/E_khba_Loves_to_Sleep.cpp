#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, k, x; cin >> n >> k >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    
    int l = 1, r = 1e9;
    vector<int> vans(k);
    iota(vans.begin(), vans.end(), 0);
    while (l <= r){
        int mid = (l + r) / 2;

        vector<int> v;
        for (int j = 0; j <= a[0] - mid; j++){
            v.push_back(j);
            if (v.size() == k){
                break;
            }
        }
        if (v.size() < k){
            for (int i = 0; i < a.size() - 1; i++){
                for (int j = a[i] + mid; j <= a[i + 1] - mid; j++){
                    v.push_back(j);
                    if (v.size() == k){
                        i = a.size();
                        break;
                    }
                }
            }
        }
        if (v.size() < k){
            for (int j = a.back() + mid; j <= x; j++){
                v.push_back(j);
                if (v.size() == k){
                    break;
                }
            }
        }

        if (v.size() == k){
            l = mid + 1;
            vans = v;
        } else {
            r = mid - 1;
        }
    }

    for (int i = 0; i < vans.size(); i++){
        cout << vans[i] << " \n"[i == vans.size() - 1];
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