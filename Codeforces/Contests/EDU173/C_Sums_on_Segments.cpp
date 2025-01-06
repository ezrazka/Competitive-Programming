#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

int minimum_subarray(vector<int> v){
    int n = v.size();
    vector<int> pref(n + 1);
    int res = 0;
    int mx = 0;
    for (int i = 0; i < n; i++){
        pref[i + 1] = pref[i] + v[i];
        res = min(res, pref[i + 1] - mx);
        mx = max(mx, pref[i + 1]);
    }
    return res;
}

int maximum_subarray(vector<int> v){
    int n = v.size();
    vector<int> pref(n + 1);
    int res = 0;
    int mn = 0;
    for (int i = 0; i < n; i++){
        pref[i + 1] = pref[i] + v[i];
        res = max(res, pref[i + 1] - mn);
        mn = min(mn, pref[i + 1]);
    }
    return res;
}

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    int idx = 0;
    for (int i = 0; i < n; i++){
        if (abs(v[i]) != 1){
            idx = i;
            break;
        }
    }

    int mn1 = 0;
    int cur = 0;
    for (int i = idx - 1; i >= 0; i--){
        cur += v[i];
        mn1 = min(mn1, cur);
    }

    int mn2 = 0;
    cur = 0;
    for (int i = idx + 1; i < n; i++){
        cur += v[i];
        mn2 = min(mn2, cur);
    }

    int mx1 = 0;
    cur = 0;
    for (int i = idx - 1; i >= 0; i--){
        cur += v[i];
        mx1 = max(mx1, cur);
    }

    int mx2 = 0;
    cur = 0;
    for (int i = idx + 1; i < n; i++){
        cur += v[i];
        mx2 = max(mx2, cur);
    }

    int mn = min(minimum_subarray(vector<int>(v.begin(), v.begin() + idx)), minimum_subarray(vector<int>(v.begin() + idx + 1, v.end())));
    int mx = max(maximum_subarray(vector<int>(v.begin(), v.begin() + idx)), maximum_subarray(vector<int>(v.begin() + idx + 1, v.end())));

    set<int> st;
    for (int i = mn; i <= mx; i++){
        st.insert(i);
    }
    for (int i = mn1 + mn2 + v[idx]; i <= mx1 + mx2 + v[idx]; i++){
        st.insert(i);
    }

    cout << st.size() << '\n';
    for (int x : st){
        cout << x << ' ';
    }
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}