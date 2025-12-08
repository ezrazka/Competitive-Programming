#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    string s, t; cin >> s >> t;
    int n = s.length(), m = t.length();

    map<char, int> mps, mpt;
    for (int i = 0; i < n; i++) mps[s[i]]++;
    for (int i = 0; i < m; i++) mpt[t[i]]++;

    for (auto [letter, freq] : mps){
        if (freq > mpt[letter]){
            cout << "Impossible\n";
            return;
        }
    }

    vector<int> freq(26);
    for (char c : t){
        freq[c - 'a']++;
    }

    vector<vector<char>> v(26);
    int i = 0;
    for (char c = 'a'; c <= 'z'; c++){
        while (freq[c - 'a']--){
            if (i < n && s[i] == c){
                i++;
            }
            v[c - 'a'].push_back(c);
            while (i < n && s[i] < c){
                v[s[i] - 'a'].pop_back();
                v[c - 'a'].push_back(s[i]);
                i++;
            }
        }
    }

    for (int i = 0; i < 26; i++){
        for (char x : v[i]){
            cout << x;
        }
    }
    cout << '\n';

    /*
    find lexicographically smallest permuration of t where s is a substring
    'Impossible' if none exist
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}