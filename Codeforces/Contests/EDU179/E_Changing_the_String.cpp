#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, q; cin >> n >> q;
    string s; cin >> s;

    vector<vector<int>> v(3, vector<int>(3));
    for (int i = 0; i < q; i++){
        char a, b; cin >> a >> b;
        v[a - 'a'][b - 'a']++;
    }

    for (int i = 0; i < n; i++){
        if (s[i] == 'b'){
            if (v[1][0]){
                s[i] = 'a';
                v[1][0]--;
            } else if (v[1][2] && v[2][0]){
                s[i] = 'a';
                v[1][2]--, v[2][0]--;
            }
        } else if (s[i] == 'c'){
            if (v[2][0]){
                s[i] = 'a';
                v[2][0]--;
            } else if (v[2][1] && v[1][0]){
                s[i] = 'a';
                v[2][1]--, v[1][0]--;
            } else if (v[2][1]){
                s[i] = 'b';
                v[2][1]--;
            }
        }
    }// remember order

    cout << s << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}