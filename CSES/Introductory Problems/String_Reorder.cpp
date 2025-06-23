#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    string s; cin >> s;
    int n = s.length();

    vector<int> freq(26);
    for (int i = 0; i < n; i++){
        freq[s[i] - 'A']++;
    }

    string ans;
    for (int i = 0; i < n; i++){
        int smallest = -1;
        int mode = -1;
        for (int c = 0; c < 26; c++){
            if (freq[c] > 0 && smallest == -1 && (ans.empty() || ans[i - 1] != 'A' + c)){
                smallest = c;
            }
            if (freq[c] > 0 && (mode == -1 || freq[c] > freq[mode])){
                mode = c;
            }
        }
        if (freq[mode] > (n - i) - freq[mode]){
            ans += 'A' + mode;
            freq[mode]--;
        } else {
            ans += 'A' + smallest;
            freq[smallest]--;
        }
    }

    for (int i = 0; i < n - 1; i++){
        if (ans[i] == ans[i + 1]){
            cout << "-1\n";
            return;
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