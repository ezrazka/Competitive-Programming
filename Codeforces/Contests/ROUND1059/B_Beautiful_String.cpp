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
    string s; cin >> s;

    for (int mask = 0; mask < (1 << n); mask++){
        vector<int> a, b;
        for (int i = 0; i < n; i++){
            if (mask & (1 << i)){
                a.push_back(i);
            } else {
                b.push_back(i);
            }
        }
        bool is_palindrome = true;
        for (int i = 0; i < a.size() / 2; i++){
            if (s[a[i]] != s[a[a.size() - 1 - i]]){
                is_palindrome = false;
            }
        }
        bool is_sorted = true;
        for (int i = 0; i < (int) b.size() - 1; i++){
            if (s[b[i]] > s[b[i + 1]]){
                is_sorted = false;
            }
        }
        if (is_palindrome && is_sorted){
            cout << b.size() << '\n';
            for (int i = 0; i < b.size(); i++){
                cout << b[i] + 1 << " \n"[i == b.size() - 1];
            }
            return;
        }
    }

    cout << -1 << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}