#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<int> freq(n + 1);
    for (int i = 0; i < n; i++){
        freq[v[i]]++;
    }

    vector<int> last3;
    for (int i = n - 1; i >= 0; i--){
        if (last3.size() == 3) break;
        bool found = false;
        for (int x : last3){
            if (v[i] == x){
                found = true;
            }
        }
        if (found) continue;
        last3.push_back(v[i]);
    }
    for (int i = 1; i <= n; i++){
        if (!freq[i] && last3.size()){
            last3.push_back(i);
        }
    }

    reverse(last3.begin(), last3.end());
    for (int i = 0; i < k; i++){
        cout << last3[i % 3] << " \n"[i == k - 1];
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