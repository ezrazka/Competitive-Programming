#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m; cin >> n >> m;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i;
    sort(a.begin(), a.end());

    vector<pair<int, int>> vans;

    if (m > n / 2){
        cout << "-1\n";
        return;
    }
    
    int sum = 0;
    for (int i = 0; i < n - 1; i++){
        sum += a[i].first;
    }
    bool can0 = sum >= a[n - 1].first;

    if (!can0 && m == 0){
        cout << "-1\n";
        return;
    }

    if (can0 && m == 0){
        int j = 0;
        while (sum - a[j].first >= a[n - 1].first){
            sum -= a[j].first;
            j++;
        }
        for (int i = 0; i < j; i++){
            vans.emplace_back(a[i].second, a[i + 1].second);
        }
        for (int i = j; i < n - 1; i++){
            vans.emplace_back(a[i].second, a[n - 1].second);
        }
    } else {
        for (int i = 0; i < n - 2 * m; i++){
            vans.emplace_back(a[i].second, a[i + 1].second);
        }
        for (int i = n - 2 * m; i < n; i += 2){
            vans.emplace_back(a[i + 1].second, a[i].second);
        }
    }

    cout << vans.size() << '\n';
    for (int i = 0; i < vans.size(); i++){
        cout << vans[i].first + 1 << ' ' << vans[i].second + 1 << '\n';
    }

    /*
    disable 1: x attacks y where ax < hy and ay > hx
    disable 2: x attacks y where ax >= hy

    0 <= m <= n / 2
    continue while: * at least 2 are alive, and at least 1 has not attacked

    step 1: generalize even and odd
        if odd {
            a[1] attacks a[2], n--;
            erase a[1];
        }
    step 2:


    prefix and a suffix
    the suffix si already correct

    to get 0
    well delete a prefix
    such that the leftover prefix exactly kills last element

    to get 1
    just go sequentially

    to get >1
    go sequentially and leave behind 2 * m elements
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