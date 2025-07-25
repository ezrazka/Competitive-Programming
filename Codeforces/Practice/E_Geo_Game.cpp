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
    int start = 0;
    {
        int x, y; cin >> x >> y;
        start ^= x & 1;
        start ^= y & 1;
    }
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        v[i] ^= x & 1;
        v[i] ^= y & 1;
    }

    vector<set<int>> idxs(2);
    for (int i = 0; i < n; i++){
        idxs[v[i]].insert(i);
    }

    bool first = idxs[start].size() >= idxs[!start].size();

    cout << (first ? "First" : "Second") << endl;
    for (int i = 0; i < n; i++){
        if ((i & 1) ^ first){
            int target = (start ^ first ^ idxs[start ^ first].empty());
            int x = *idxs[target].begin();
            cout << x + 1 << endl;
            idxs[target].erase(x);
        } else {
            int x; cin >> x; x--;
            int target = (idxs[0].find(x) == idxs[0].end());
            idxs[target].erase(x);
        }
    }

    /*
    observation:
    the parity of the xor of the x and y values of the first and last coordinates
    must be the same if and only if First wins

    proof:
    the parity between turns only changes if (cur ^ prev) is 1
    and since all non first and last coords cancel out themselves (because they always appear twice),
    only the first and last coordinates matter
    
    greedy strategy:
    choose First if and only if idxs[start].size() >= idxs[!start].size()
    if First: always prioritize taking the different parity as start
    if Second: always prioritize taking the same parity as start
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