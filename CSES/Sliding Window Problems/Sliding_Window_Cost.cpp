#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cerr << "(" << #x << " : " << (x) << ")\n"
#define debughere cerr << "HERE\n"

void solve(){
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    multiset<int> ms1, ms2;
    auto insert = [&](int val){
        if (ms2.empty() || val <= *ms2.begin()){
            ms1.insert(val);
        } else {
            ms2.insert(val);
        }
    };
    auto erase = [&](int val){
        if (ms1.find(val) != ms1.end()){
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
    
    int cost = 0;
    for (int i = 0; i < k; i++){
        {

            insert(v[i]);
            int median = get_median();
            cost += abs(v[i] - median);
        }
    }
    cout << cost << ' ';
    for (int i = k; i < n; i++){
        {
            insert(v[i]);
            int median = get_median();
            cost += abs(v[i] - median);
        }
        {
            erase(v[i - k]);
            int median = get_median();
            cost -= abs(v[i - k] - median);
        }
        cout << cost << ' ';
    }
    cout << '\n';

    /*
    1 2, remove 1, delete from new median
    1 2 3, remove 3, delete from old median

    if median increases by x (new_median - old_median == x),
        then all values <= old_median (say y values) increase by x
        ans otherwise decrease by x
    therefore, if a median changes,
    1. cost increases by y * cost - (total - y) * cost
    2. when an item is added, we decrease by 10
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}