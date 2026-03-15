#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    int zeros = count(s.begin(), s.end(), '0');
    int ones = n - zeros;

    if (ones == 0){
        cout << 0 << '\n';
        return;
    }

    if (zeros % 2 == 0 && ones % 2 == 1){
        cout << -1 << '\n';
        return;
    }

    vector<int> vans;
    if (zeros % 2 == 0 && ones % 2 == 0){
        for (int i = 0; i < n; i++){
            if (s[i] == '1'){
                vans.push_back(i);
            }
        }
    } else {
        for (int i = 0; i < n; i++){
            if (s[i] == '0'){
                vans.push_back(i);
            }
        }
    }

    cout << vans.size() << '\n';
    for (int i = 0; i < vans.size(); i++){
        cout << vans[i] + 1 << " \n"[i == vans.size() - 1];
    }
    /*
    odd even -> 0
    even odd -> -1
    odd odd -> 0
    even even 1
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