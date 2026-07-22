#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    string s; cin >> s;

    vector<int> vans;
    debug(s);
    cout << flush;
    auto rec = [&](auto self, int sum, vector<int> freq) -> int {
        debug(sum);
        if (sum <= 9){
            vans.push_back(sum);
            return true;
        }
        vector<int> i_freq(10);
        int i_sum = 0;
        for (int i = 1; i <= sum; i++){
            cout << i << endl;
            bool ok = true;
            {
                int temp = i;
                while (temp > 0){
                    i_freq[temp % 10]++;
                    i_sum += temp % 10;
                    if (i_freq[temp % 10] > freq[temp % 10]) ok = false;
                    temp /= 10;
                }
            }
            if (ok){
                vector<bool> dp(sum - i_sum + 1);
                dp[0] = true;
                {
                    int temp = i;
                    while (temp > 0){
                        int x = temp % 10;
                        for (int j = sum - i_sum; j >= x; j--){
                            dp[j] = dp[j] | dp[j - x];
                        }
                        temp /= 10;
                    }
                }
                if (dp[sum - i_sum]) if (self(self, i, i_freq)){
                    vans.push_back(sum - i_sum);
                    return true;
                }
            }
            {
                int temp = i;
                while (temp > 0){
                    i_freq[temp % 10]--;
                    i_sum -= temp % 10;
                    temp /= 10;
                }
            }
        }
        return false;
    };
    {
        vector<int> freq(10);
        int sum = 0;
        for (char c : s) freq[c - '0']++, sum += c - '0';
        rec(rec, sum, freq);
    }

    for (int i = (int) vans.size() - 1; i >= 0; i--){
        cout << vans[i];
    }
    cout << '\n';

    /*
       find split where
       multiset{sum of digits in A} == multiset{digits in B}
       the max possible sum is 9 * s.length()
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
