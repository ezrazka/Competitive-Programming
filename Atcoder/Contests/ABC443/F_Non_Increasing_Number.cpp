#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    
    {
        if (n % 10 == 0){
            cout << "-1\n";
            return;
        }
    
        bool ok = false;
        for (int i = 1; i <= 100; i++){
            string s = to_string(i * n);
            if (is_sorted(s.begin(), s.end())){
                cout << i * n << '\n';
                return;
            }
        }
        if (!ok){
            cout << "-1\n";
            return;
        }
    }
    cout << 0 << '\n';

    /*
        possibly check all valid numbers, then check n is a factor? if so, we just check within range
        the last digit must be >= 1
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