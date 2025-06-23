#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int qq; cin >> qq;

    vector<int> fact(21);
    fact[0] = 1;
    for (int i = 1; i <= 20; i++){
        fact[i] = fact[i - 1] * i;
    }

    if (qq == 1){
        int n, k; cin >> n >> k; k--;
        vector<int> freq(n);
        int temp = k;
        for (int i = n - 1; i >= 0; i--){
            freq[i] = temp / fact[i];
            temp -= temp / fact[i] * fact[i];
        }

        vector<int> nums(n);
        iota(nums.begin(), nums.end(), 1);

        vector<int> p;
        for (int i = n - 1; i >= 0; i--){
            p.push_back(nums[freq[i]]);
            nums.erase(nums.begin() + freq[i]);
        }

        for (int i = 0; i < n; i++){
            cout << p[i] << " \n"[i == n - 1];
        }
    } else {
        int n; cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++){
            cin >> p[i];
        }

        vector<int> nums(n);
        iota(nums.begin(), nums.end(), 1);

        int k = 0;
        for (int i = 0; i < n; i++){
            int idx = find(nums.begin(), nums.end(), p[i]) - nums.begin();
            k += idx * fact[n - i - 1];
            nums.erase(nums.begin() + idx);
        }
        k++;
        cout << k << '\n';
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