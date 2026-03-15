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

    int ans = 1;
    vector<int> v = {n - 1};
    int sum = n - 1, cnt = 1;
    for (int i = n - 2; i >= 0; i--){
        if (a[i + 1] - a[i] >= 2){
            a[v.back()] = 0;
        } else if (a[i] + 1 == a[i + 1]){
            while (!v.empty() && a[v.back()] > a[i]){
                sum -= v.back();
                cnt--;
                v.pop_back();
            }
        }
        v.push_back(i);
        sum += i, cnt++;
        ans += cnt * n - sum;
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}