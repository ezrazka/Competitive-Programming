#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, x, y; cin >> n >> x >> y;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> inner, outer;
    for (int i = 0; i < n; i++){
        if (x <= i && i < y) inner.push_back(a[i]);
        else outer.push_back(a[i]);
    }

    if (!inner.empty()){
        int mn_index = min_element(inner.begin(), inner.end()) - inner.begin();
        rotate(inner.begin(), inner.begin() + mn_index, inner.end());
    }

    if (outer.empty()){
        for (int i = 0; i < inner.size(); i++){
            cout << inner[i] << " \n"[i == inner.size() - 1];
        }
    } else {
        bool printed = inner.empty();
        for (int i = 0; i < outer.size(); i++){
            if (!printed && outer[i] > inner[0]){
                for (int j = 0; j < inner.size(); j++){
                    cout << inner[j] << ' ';
                }
                printed = true;
            }
            cout << outer[i] << ' ';
        }
        if (!printed){
            for (int i = 0; i < inner.size(); i++){
                cout << inner[i] << ' ';
            }
        }
        cout << '\n';
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