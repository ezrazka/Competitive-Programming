#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int base; cin >> base;
    int n; cin >> n;

    vector<int> pow_10(13);
    pow_10[0] = 1;
    for (int i = 1; i <= 12; i++){
        pow_10[i] = pow_10[i - 1] * 10;
    }

    auto reverse_num = [&](int num){
        int res = 0;
        while (num > 0){
            res *= 10;
            res += num % 10;
            num /= 10;
        }
        return res;
    };

    auto to_base_string = [&](int num){
        string res;
        while (num > 0){
            res += '0' + (num % base);
            num /= base;
        }
        return res;
    };

    auto is_palindrome = [&](int num){
        string s = to_string(num);
        for (int i = 0; i < s.length() / 2; i++){
            if (s[i] != s[s.length() - 1 - i]){
                return false;
            }
        }
        return true;
    };

    auto is_palindrome_string = [&](string s){
        for (int i = 0; i < s.length() / 2; i++){
            if (s[i] != s[s.length() - 1 - i]){
                return false;
            }
        }
        return true;
    };

    vector<int> nums;
    auto rec = [&](auto self, int i, int num) -> void {
        if (1 <= i && i <= 6){
            int a = reverse_num(num / 10) + pow_10[i - 1] * num;
            if (is_palindrome(a) && is_palindrome_string(to_base_string(a))){
                nums.push_back(a);
            }
            int b = reverse_num(num) + pow_10[i] * num;
            if (is_palindrome(b) && is_palindrome_string(to_base_string(b))){
                nums.push_back(b);
            }
        }
        if (i == 6){
            return;
        }

        for (int x = 0; x < 10; x++){
            self(self, i + 1, x + 10 * num);
        }
    };
    rec(rec, 0, 0);

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    int ans = 0;
    for (int num : nums){
        if (num <= n){
            ans += num;
        }
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}