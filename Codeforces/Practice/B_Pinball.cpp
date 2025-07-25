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

    vector<int> pref(n + 1), suff(n + 1);
    for (int i = 0; i < n; i++){
        pref[i + 1] = pref[i] + (s[i] == '>' ? i : 0);
        suff[i + 1] = suff[i] + (s[(n - 1) - i] == '<' ? (n - 1) - i : 0);
    }

    vector<int> pref_idxs, suff_idxs;
    for (int i = n - 1; i >= 0; i--){
        if (s[i] == '<'){
            suff_idxs.push_back(i);
        }
    }

    vector<int> vans(n);
    for (int i = 0; i < n; i++){
        {
            if (i > 0 && s[i - 1] == '>'){
                pref_idxs.push_back(i - 1);
            }
            if (s[i] == '<'){
                suff_idxs.pop_back();
            }
        }
        {
            if (s[i] == '<'){
                if (pref_idxs.size() <= suff_idxs.size()){
                    if (!pref_idxs.empty()){
                        vans[i] += 2 * ((pref_idxs.size() * i) - (pref[i] - pref[pref_idxs[0]]));
                        vans[i] += 2 * ((suff[(n - 1) - i] - suff[(n - 1) - suff_idxs[suff_idxs.size() - pref_idxs.size()]]) - (pref_idxs.size() * i));
                    }
                    vans[i] += i + 1;
                } else {
                    if (!suff_idxs.empty()){
                        vans[i] += 2 * ((suff[(n - 1) - i] - suff[(n - 1) - suff_idxs[0]]) - (suff_idxs.size() * i));
                        vans[i] += 2 * ((suff_idxs.size() * i) - (pref[i] - pref[pref_idxs[pref_idxs.size() - suff_idxs.size()]]));
                    }
                    vans[i] += 2 * (i - pref_idxs[pref_idxs.size() - (suff_idxs.size() + 1)]);
                    vans[i] += n - i;
                }
            } else {
                if (suff_idxs.size() <= pref_idxs.size()){
                    if (!suff_idxs.empty()){
                        vans[i] += 2 * ((suff[(n - 1) - i] - suff[(n - 1) - suff_idxs[0]]) - (suff_idxs.size() * i));
                        vans[i] += 2 * ((suff_idxs.size() * i) - (pref[i] - pref[pref_idxs[pref_idxs.size() - suff_idxs.size()]]));
                    }
                    vans[i] += n - i;
                } else {
                    if (!pref_idxs.empty()){
                        vans[i] += 2 * ((pref_idxs.size() * i) - (pref[i] - pref[pref_idxs[0]]));
                        vans[i] += 2 * ((suff[(n - 1) - i] - suff[(n - 1) - suff_idxs[suff_idxs.size() - pref_idxs.size()]]) - (pref_idxs.size() * i));
                    }
                    vans[i] += 2 * (suff_idxs[suff_idxs.size() - (pref_idxs.size() + 1)] - i);
                    vans[i] += i + 1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++){
        cout << vans[i] << " \n"[i == n - 1];
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