#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

constexpr int INF = 1e18;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    {
        vector<int> b = a;
        a.clear();
        bool found = false;
        for (int i = 0; i < n; i++){
            if (b[i] != 0){
                a.push_back(b[i]);
            } else if (!found){
                a.push_back(b[i]);
                found = true;
            }
        }
        n = a.size();
    }

    vector<int> pref(n + 1, INF);
    for (int i = 1; i <= n; i++){
        pref[i] = min(pref[i - 1], a[i - 1]);
    }

    bool ok = true;
    set<int> mex;
    for (int i = 0; i < n; i++) mex.insert(i);
    for (int i = n - 1; i >= 1; i--){
        if (mex.find(a[i]) != mex.end()) mex.erase(a[i]);
        if (pref[i] < *mex.begin()) ok = false;
    }

    cout << (ok ? n : n - 1) << '\n';

    /*
    Observations:
        * A permutation is always valid
        * A subsequence may have at most one 0
        * A subsequence is invalid iff there exiss at least one X that comes before all of [0..X]
        * A subsequence is always at least better than the original array
            (if its added to the left partition, the minimum can only get smaller)
            (if its added to the right partition, the mex can only get larger)
        * All subsequences not containing 0 are valid
    
    Since we can only have at most one 0,
    and all subsequences not containing 0 are valid,

    then we can show that:
        if the subsequence generated from greedily removing all but one rightmost 0s is valid
            the answer is n - freq[0] + 1
        otherwise
            the answer is n - freq[0]
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