#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const vector<string> v = {"OX", "XXX", "OXOXOXOXX"};
vector<vector<int>> amounts(3, vector<int>(3));

void init(){
    auto calc = [&](string x, string y){
        string s = x + y;
        set<string> st;
        for (int i = 0; i < s.length(); i++){
            for (int j = i; j < s.length(); j++){
                st.insert(s.substr(i, j - i + 1));
            }
        }
        return st.size();
    };

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            amounts[i][j] = calc(v[i], v[j]);
        }
    }
}

void solve(){
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        cout << v[i] << endl;
    }

    int q; cin >> q;
    while (q--){
        int x; cin >> x;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (amounts[i][j] == x){
                    cout << i + 1 << ' ' << j + 1 << endl;
                    i = n, j = n;
                }
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    init();
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}