#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

string query(int r1, int c1, int r2, int c2){
    cout << "? " << r1 + 1 << ' ' << c1 + 1 << ' ' << r2 + 1 << ' ' << c2 + 1 << endl;
    string s; cin >> s;
    return s;
}

void answer(string s){
    cout << "! " << s << endl;
}

void solve(){
    int n; cin >> n;

    string ans1, ans2;
    int r1 = 0, c1 = 0;
    for (int _ = 0; _ < n - 1; _++){
        string q = query(r1, c1 + 1, n - 1, n - 1);
        if (q == "YES"){
            c1++;
            ans1 += 'R';
        } else {
            r1++;
            ans1 += 'D';
        }
    }
    int r2 = n - 1, c2 = n - 1;
    for (int _ = 0; _ < n - 1; _++){
        string q = query(0, 0, r2 - 1, c2);
        if (q == "YES"){
            r2--;
            ans2 += 'D';
        } else {
            c2--;
            ans2 += 'R';
        }
    }

    string ans;
    ans += ans1;
    reverse(ans2.begin(), ans2.end());
    ans += ans2;
    answer(ans);
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}