#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

int query(vector<int> &v){
    cout << "? ";
    cout << v.size() << ' ';
    for (int x : v){
        cout << x + 1 << ' ';
    }
    cout << endl;
    int res; cin >> res;
    return res;
}

void answer(vector<int>& v){
    cout << "! ";
    for (int x : v){
        cout << x << ' ';
    }
    cout << endl;
}

void solve(){
    int n; cin >> n;

    vector<int> vans1(2 * n);
    {
        for (int i = 0; i < 2 * n; i++){
            vector<int> idxs;
            for (int j = 0; j <= i; j++){
                if (vans1[j] == 0){
                    idxs.push_back(j);
                }
            }
            int q = query(idxs);
            vans1[i] = q;
        }
    }
    vector<int> vans2(2 * n);
    {
        for (int i = 2 * n - 1; i >= 0; i--){
            if (vans1[i] != 0) continue;
            vector<int> idxs;
            for (int j = 2 * n - 1; j >= 0; j--){
                if (vans2[j] == 0 && (vans1[j] != 0 || j >= i)){
                    idxs.push_back(j);
                }
            }
            int q = query(idxs);
            vans2[i] = q;
        }
    }
    vector<int> vans;
    for (int i = 0; i < 2 * n; i++){
        vans.push_back(max(vans1[i], vans2[i]));
    }
    answer(vans);
    /*
    in one iteration, find all second occurences
    then in one iteration find all first occurences (but eliminate the other n, so 3n operations)
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