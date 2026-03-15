#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    string s; cin >> s;
    int n = s.length();
    sort(s.begin(), s.end());

    vector<int> freq(26);
    for (int i = 0; i < n; i++){
        freq[s[i] - 'a']++;
    }

    char mn1 = '$', mn2 = '$', mn3 = '$';
    int cnt_mn1, cnt_mn2, cnt_mn3;
    for (int i = 0; i < 26; i++){
        if (freq[i] == 0) continue;
        if (mn1 == '$') mn1 = 'a' + i, cnt_mn1 = freq[i];
        else if (mn2 == '$') mn2 = 'a' + i, cnt_mn2 = freq[i];
        else if (mn3 == '$') mn3 = 'a' + i, cnt_mn3 = freq[i];
    }

    if (cnt_mn1 == n){
        cout << s << '\n';
        return;
    }

    for (int i = 0; i < 26; i++){
        if (freq[i] == 1){
            cout << (char) ('a' + i);
            for (int j = 0; j < n; j++){
                if (s[j] == 'a' + i) continue;
                cout << s[j];
            }
            cout << '\n';
            return;
        }
    }

    if (cnt_mn1 >= 2 && cnt_mn1 - 2 <= n - cnt_mn1){
        cout << mn1;
        cout << mn1;
        for (int i = 2, j = 0; i < n; i++){
            if (s[i] == mn1) continue;
            cout << s[i];
            if (j < cnt_mn1 - 2) cout << mn1;
            j++;
        }
        cout << '\n';
        return;
    }

    if (cnt_mn1 + cnt_mn2 == n){
        cout << mn1;
        for (int _ = 0; _ < cnt_mn2; _++) cout << mn2;
        for (int _ = 0; _ < cnt_mn1 - 1; _++) cout << mn1;
        cout << '\n';
        return;
    }
    
    cout << mn1;
    cout << mn2;
    for (int _ = 0; _ < cnt_mn1 - 1; _++) cout << mn1;
    cout << mn3;
    for (int _ = 0; _ < cnt_mn2 - 1; _++) cout << mn2;
    for (int _ = 0; _ < cnt_mn3 - 1; _++) cout << mn3;
    for (int i = 0; i < n; i++){
        if (s[i] != mn1 && s[i] != mn2 && s[i] != mn3){
            cout << s[i];
        }
    }
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}