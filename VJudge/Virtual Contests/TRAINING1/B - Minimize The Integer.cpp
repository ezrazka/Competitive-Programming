#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    string s; cin >> s;
    int n = s.length();

    vector<char> nums[2];
    for (char c : s) {
        nums[(c - '0') & 1].push_back(c);
    }

    int ptr[2] = {};
    while (ptr[0] < nums[0].size() && ptr[1] < nums[1].size()) {
        if (nums[0][ptr[0]] < nums[1][ptr[1]]) {
            cout << nums[0][ptr[0]++];
        } else {
            cout << nums[1][ptr[1]++];
        }
    }
    while (ptr[0] < nums[0].size()) cout << nums[0][ptr[0]++];
    while (ptr[1] < nums[1].size()) cout << nums[1][ptr[1]++];
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
