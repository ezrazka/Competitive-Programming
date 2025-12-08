#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

string bin(int n){
    string s;
    while (n){
        s += '0' + (n & 1);
        n >>= 1;
    }
    return s;
}

bool is_palindrome(string s){
    while (!s.empty() && s[0] == '0') s = s.substr(1);
    int n = s.length();
    for (int i = 0; i < n / 2; i++){
        if (s[i] != s[n - 1 - i]) return false;
    }
    return true;
}

void solve(){
    int n; cin >> n;
    cout << (__builtin_popcount(n) % 2 == 0 && is_palindrome(bin(n)) ? "YES\n" : "NO\n");
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}