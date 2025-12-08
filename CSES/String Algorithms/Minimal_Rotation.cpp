#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    string s; cin >> s;
    s += s.substr(0, s.length() - 1);
    int n = s.length();

    vector<int> a(n);
    vector<vector<int>> lengths(n + 1);
    {
        char mn = *min_element(s.begin(), s.end());
        for (int i = 0; i < n; i++){
            a[i] = (s[i] == mn);
            lengths[a[i]].push_back(i);
        }
    }
    
    int length = 1;
    vector<bool> skip(n);
    stack<int> skipped;
    auto merge = [&](){
        int new_length = length;
        for (int i : lengths[length]){
            if (skip[i]) continue;
            if (i + a[i] >= n || a[i + a[i]] == 0) continue;
            while (i + a[i] < n && a[i + a[i]] > 0){
                a[i] += a[i + a[i]];
                skipped.push(i + a[i]);
                skip[skipped.top()] = true;
            }
            lengths[a[i]].push_back(i);
            new_length = max(new_length, a[i]);
        }
        while (!skipped.empty()){
            skip[skipped.top()] = false;
            skipped.pop();
        }
        length = new_length;
    };
    auto extend = [&](){
        char mn = 'z';
        for (int i : lengths[length]){
            if (i + a[i] >= n) continue;
            mn = min(mn, s[i + a[i]]);
        }
        for (int i : lengths[length]){
            if (i + a[i] >= n) continue;
            if (s[i + a[i]] != mn) continue;
            a[i]++;
            lengths[a[i]].push_back(i);
        }
        length++;
    };
    
    merge();
    while (length < (n + 1) / 2){
        extend();
        merge();
    }
    
    cout << s.substr(max_element(a.begin(), a.end()) - a.begin(), (n + 1) / 2) << '\n';

    /*
        1. extend longest length
        2. merge
        3. update length
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}