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
    map<int, int> mp;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        mp[x]++;
    }

    vector<pair<int, int>> v;
    for (auto [x, y] : mp){
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());
    n = v.size();

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j){
        return make_pair(v[i].se, v[i].fi) < make_pair(v[j].se, v[j].fi);
    });

    vector<bool> to_take(n);
    for (int i : ord){
        int alice_ptr = 0, bob_ptr = 0;
        vector<int> taken(n);
        auto temp = v;
        bool ok = true;
        int cnt_to_take = 0;
        while (alice_ptr < n){
            while (alice_ptr < n && taken[alice_ptr] == 2){
                alice_ptr++;
            }
            if (alice_ptr < n){
                taken[alice_ptr] = 1;
                alice_ptr++;
            }
            while (bob_ptr < n && (!to_take[bob_ptr] && i != bob_ptr)){
                bob_ptr++;
            }
            if (bob_ptr < n){
                if (taken[bob_ptr] == 1){
                    ok = false;
                    break;
                }
                if (temp[bob_ptr].se == 1){
                    cnt_to_take++;
                    taken[bob_ptr] = 2;
                    bob_ptr++;
                } else {
                    temp[bob_ptr].se--;
                }
            }
        }
        if (ok && count(to_take.begin(), to_take.end(), true) < cnt_to_take){
            to_take[i] = true;
        }
    }
    cout << count(to_take.begin(), to_take.end(), false) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}