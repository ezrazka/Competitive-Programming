#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i < n; i++){
        int need = a[i] - (n - i) + 1;
        if (need < 0 || need > i + 1 || a[i] > n || i < n - 1 && a[i] < a[i + 1]){
            cout << "NO\n";
            return;
        }
    }
    
    vector<int> vans(n, -1);
    vector<int> mx(n);
    vector<bool> used(n + 1);
    for (int i = 0; i < n; i++) used[a[i]] = true;
    for (int i = n - 1, j = 0, k = 0; i >= 0; i--){
        int need = a[i] - (n - i) + 1;
        if (i == 0 && need == 0 || i != 0 && a[i - 1] > a[i]){
            vans[i] = n + 1;
            continue;
        }
        j = max(j, mx[k]);
        if (k + need < n) mx[k + need] = max(mx[k + need], a[i] + 1);
        while (used[j]) j++;
        vans[i] = j++;
        k++;
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++){
        cout << vans[i] << " \n"[i == n - 1];
    }

    /*
    Observations:
    * a must be non-increasing, and a[i] - a[i + 1] <= 1
    * when a[i] == a[i + 1], b[i] must be a new number <a[i]
        * since it 
    * when a[i] > a[i + 1], b[i] must be a number >a[i + 1]
    * a[i] = x means there exists x - (n - i + 1) + 1 unique values below x, and none equal to x
    * for i < n, a[i] == a[i + 1] means we add a new value <a[i + 1]
                 a[i] - 1 == a[i + 1] means we add a value >a[i + 1]

    3 3 1
    1 2 1
    ----
    2 1 3
    0 0 3
    ----
    0
    0
    ----
    2
    2
    ----
    7 5 2 2
    4 3 1 2
    ----
    6 6 6 4 3 3
    1 2 3 2 2 3
    ----
    0 1 5 - - 2
    5 2 1 - - 0

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