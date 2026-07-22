#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    string best = string(n, '0');
    while (k--) {
        pair<string, int> ans1 = {best, n + 1}, ans2 = {best, n + 1};
        {
            for (int i = 0; i < n; i++) {
                if (ans1.first[i] - '0') continue;
                if (s[i] == '(') {
                    ans1.first[i] = '1';
                    break;
                }
            }
            ans1.second = 0;
            int open = 0;
            for (int i = 0; i < n; i++) {
                if (ans1.first[i] - '0') continue;
                if (s[i] == '(') open++;
                else if (open > 0) open--, ans1.second += 2;
            }
        }
        {
            for (int i = n - 1; i >= 0; i--) {
                if (ans2.first[i] - '0') continue;
                if (s[i] == ')') {
                    ans2.first[i] = '1';
                    break;
                }
            }
            ans2.second = 0;
            int open = 0;
            for (int i = 0; i < n; i++) {
                if (ans2.first[i] - '0') continue;
                if (s[i] == '(') open++;
                else if (open > 0) open--, ans2.second += 2;
            }
        }
        best = (ans1.second < ans2.second ? ans1.first : ans2.first);
    }
    cout << best << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
