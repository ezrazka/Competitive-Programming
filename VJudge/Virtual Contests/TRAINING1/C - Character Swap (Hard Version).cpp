#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    string t; cin >> t;

    vector<int> freq(26);
    for (char c : s) freq[c - 'a']++;
    for (char c : t) freq[c - 'a']++;

    if (any_of(freq.begin(), freq.end(), [&](int x){ return x & 1; })) {
        cout << "No\n";
    } else {
        cout << "Yes\n";

        vector<pair<int, int>> vans;
        for (int i = 0; i < n; i++) {
            if (s[i] == t[i]) continue;
            bool done = false;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    vans.push_back({j, i});
                    swap(s[j], t[i]);
                    done = true;
                    break;
                }
            }
            if (done) continue;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == t[j]) {
                    vans.push_back({i + 1, j});
                    swap(s[i + 1], t[j]);
                    vans.push_back({i + 1, i});
                    swap(s[i + 1], t[i]);
                    done = true;
                    break;
                }
            }
        }

        cout << vans.size() << '\n';
        for (int i = 0; i < vans.size(); i++) {
            cout << vans[i].first + 1 << ' ' << vans[i].second + 1 << '\n';
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
