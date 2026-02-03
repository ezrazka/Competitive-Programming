#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

vector<int> pow9(18 + 1);

void init(){
    pow9[0] = 1;
    for (int i = 1; i <= 18; i++){
        pow9[i] = pow9[i - 1] * 9;
    }
}

int calc(int x){
    if (x < 0) return 0;
    if (x == 0) return 1;

    string s = to_string(x);
    int n = s.length();

    int start = n - 1;
    for (int i = 0; i < n - 1; i++){
        if (s[i] == s[i + 1]){
            start = i + 1;
            break;
        }
    }

    int res = (start == n - 1 && (s.length() < 2 || s[n - 2] != s[n - 1]));
    for (int i = start; i >= 0; i--){
        int digit = s[i] - '0';
        int cnt = digit - (i > 0 && digit - 1 >= s[i - 1] - '0');
        res += cnt * pow9[(n - 1) - i];
    }
    for (int i = 0; i <= n - 2; i++){
        res += pow9[i];
    }
    return res;
}

void solve(){
    int a, b; cin >> a >> b;
    cout << calc(b) - calc(a - 1) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    init();
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}