#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    multiset<int> ms1, ms2;
    auto insert = [&](int val){
        if (ms1.empty() || val <= *ms1.rbegin()){
            ms1.insert(val);
        } else {
            ms2.insert(val);
        }
    };
    auto erase = [&](int val){
        if (!ms1.empty() && val <= *ms1.rbegin()){
            ms1.erase(ms1.find(val));
        } else {
            ms2.erase(ms2.find(val));
        }
    };
    auto balance = [&](){
        while (ms1.size() > ms2.size() + 1){
            ms2.insert(*ms1.rbegin());
            ms1.erase(--ms1.end());
        }
        while (ms1.size() < ms2.size()){
            ms1.insert(*ms2.begin());
            ms2.erase(ms2.begin());
        }
    };
    auto get_median = [&](){
        balance();
        return *ms1.rbegin();
    };

    for (int i = 0; i < k; i++){
        insert(v[i]);
    }
    cout << get_median() << ' ';
    for (int i = k; i < n; i++){
        insert(v[i]);
        erase(v[i - k]);
        cout << get_median() << ' ';
    }
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}