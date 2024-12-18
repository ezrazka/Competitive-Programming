#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

vector<int> manacher_odd(string s){
    int n = s.length();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    for (int i = 1, l = 1, r = 1; i <= n; i++){
        p[i] = max(0ll, min(p[l + (r - i)], r - i));
        while (s[i - p[i]] == s[i + p[i]]){
            p[i]++;
        }
        if (i + p[i] > r){
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(p.begin() + 1, p.end() - 1);
}

vector<int> manacher(string s){
    int n = s.length();
    string t;
    for (int i = 0; i < n; i++){
        t += '#';
        t += s[i];
    }
    t += '#';
    vector<int> p = manacher_odd(t);
    return vector<int>(p.begin() + 1, p.end() - 1);
}

void solve(){
    string s; cin >> s;
    int n = s.length();

    vector<int> p = manacher(s);

    int best = -1;
    for (int i = 0; i < 2 * n - 1; i++){
        if (best == -1 || p[best] < p[i]){
            best = i;
        }
    }

    int start = (best - p[best]) / 2 + 1;
    cout << s.substr(start, p[best] - 1) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}