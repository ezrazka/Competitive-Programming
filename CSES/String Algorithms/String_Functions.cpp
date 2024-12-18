#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    string s; cin >> s;
    int n = s.length();

    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++){
        z[i] = max(0ll, min(z[i - l], r - i));
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]){
            z[i]++;
        }
        if (i + z[i] > r){
            l = i, r = i + z[i];
        }
    }
    vector<int> pi(n);
    for (int i = 1, j = 0; i < n; i++){
        while (j > 0 && s[i] != s[j]){
            j = pi[j - 1];
        }
        if (s[i] == s[j]){
            j++;
        }
        pi[i] = j;
    }

    for (int i = 0; i < n; i++){
        cout << z[i] << " \n"[i == n - 1];
    }
    for (int i = 0; i < n; i++){
        cout << pi[i] << " \n"[i == n - 1];
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