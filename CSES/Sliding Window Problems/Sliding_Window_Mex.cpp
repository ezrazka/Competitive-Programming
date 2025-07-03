#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    map<int, int> freq;
    set<int> missing;
    for (int i = 0; i <= k; i++){
        missing.insert(i);
    }
    
    for (int i = 0; i < k; i++){
        if (v[i] < k){
            freq[v[i]]++;
            if (freq[v[i]] == 1){
                missing.erase(v[i]);
            }
        }
    }
    
    cout << *missing.begin() << ' ';
    for (int i = k; i < n; i++){
        if (v[i] < k){
            freq[v[i]]++;
            if (freq[v[i]] == 1){
                missing.erase(v[i]);
            }
        }
        if (v[i - k] < k){
            freq[v[i - k]]--;
            if (freq[v[i - k]] == 0){
                missing.insert(v[i - k]);
            }
        }
        cout << *missing.begin() << " \n"[i == n - 1];
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}