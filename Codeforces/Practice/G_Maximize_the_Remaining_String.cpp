#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    string s; cin >> s;
    int n = s.length();

    vector<int> freq(26);
    for (int i = 0; i < n; i++){
        freq[s[i] - 'a']++;
    }
    
    string ans;
    vector<bool> in_ans(26, false);
    for (int i = 0; i < n; i++){
        if (!in_ans[s[i] - 'a']){
            while (!ans.empty() && freq[ans.back() - 'a'] > 0 && ans.back() < s[i]){
                in_ans[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            in_ans[s[i] - 'a'] = true;
        }
        freq[s[i] - 'a']--;
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