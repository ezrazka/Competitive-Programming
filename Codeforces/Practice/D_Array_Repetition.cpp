#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, q; cin >> n >> q;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i].fi >> v[i].se;
    }
    vector<int> last_2(n, -1);
    for (int i = 0; i < n; i++){
        if (v[i].fi == 2){
            last_2[i] = i;
        } else if (i > 0){
            last_2[i] = last_2[i - 1];
        }
    }

    int length = 0;
    int i = 0;
    while (q--){
        int k; cin >> k;
        while (length < k){
            if (v[i].fi == 1){
                length++;
            } else {
                if (length > (int) 1e18 / (v[i].se + 1)){
                    v[i].se = ((int) 1e18 - 1) / length;
                }
                length *= (v[i].se + 1);
            }
            i++;
        }

        int cur_i = i - 1;
        int cur_length = length;
        while (true){
            if (v[cur_i].fi == 1){
                if (cur_length - (cur_i - last_2[cur_i]) < k){
                    cout << v[cur_i - (cur_length - k)].se << " \n"[q == 0];
                    break;
                }
                cur_length -= (cur_i - last_2[cur_i]);
                cur_i = last_2[cur_i];
            } else {
                cur_length /= (v[cur_i].se + 1);
                cur_i--;
                k = (k - 1) % cur_length + 1;
            }
        }
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