#include <bits/stdc++.h>
#include <queue>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    string s; cin >> s;
    int n = s.length();

    vector<int> freq(26);
    for (int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;
    }

    priority_queue<pair<int, char>> pq;
    for (char c = 'a'; c <= 'z'; c++) {
        if (freq[c - 'a'] == 0) continue;
        pq.emplace(freq[c - 'a'], c);
    }

    string ans;
    while (!pq.empty()) {
        if (pq.size() == 1 && !ans.empty() && pq.top().second == ans.back()) {
            cout << "No\n";
            return;
        }
        if (!ans.empty() && pq.top().second == ans.back()) {
            auto temp1 = pq.top(); pq.pop();
            auto temp2 = pq.top(); pq.pop();
            pq.push(temp1);
            temp2.first--;
            ans += temp2.second;
            if (temp2.first != 0) pq.push(temp2);
        } else {
            auto temp = pq.top(); pq.pop();
            temp.first--;
            ans += temp.second;
            if (temp.first != 0) pq.push(temp);
        }
    }
    cout << "Yes\n" << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
