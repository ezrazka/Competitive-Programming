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

    for (int i = n - 1; i >= 0; i--){
        int left = 0, right = 0;
        for (int j = 0; j < i; j++){
            if (v[i] <= v[j] && v[j] < 2 * n - v[i]){
                left++;
            }
        }
        for (int j = i + 1; j < n; j++){
            if (v[i] <= v[j] && v[j] < 2 * n - v[i]){
                right++;
            }
        }
        if (left >= right){
            v[i] = 2 * n - v[i];
        }
    }

    int inversions = 0;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (v[i] > v[j]){
                inversions++;
            }
        }
    }
    cout << inversions << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}