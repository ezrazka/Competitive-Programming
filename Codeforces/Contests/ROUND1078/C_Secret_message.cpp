#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

vector<int> get_factors(int n){
    vector<int> res;
    for (int i = 1; i * i <= n; i++){
        if (n % i == 0){
            res.push_back(i);
            if (i * i != n){
                res.push_back(n / i);
            }
        }
    }
    sort(res.begin(), res.end());
    return res;
}

void solve(){
    int n, k; cin >> n >> k;
    vector<string> a(k);
    for (int i = 0; i < k; i++){
        cin >> a[i];
    }

    vector<vector<bool>> has_char(n, vector<bool>(26));
    for (int i = 0; i < k; i++){
        for (int j = 0; j < n; j++){
            has_char[j][a[i][j] - 'a'] = true;
        }
    }

    for (int f : get_factors(n)){
        string ans;
        bool found = true;
        for (int i = 0; i < f; i++){
            bool ok = false;
            for (int l = 0; l < k; l++){
                char c = a[l][i];
                bool valid_letter = true;
                for (int j = i; j < n; j += f){
                    if (!has_char[j][c - 'a']){
                        valid_letter = false;
                        break;
                    }
                }
                if (valid_letter){
                    ans += c;
                    ok = true;
                    break;
                }
            }
            if (!ok){
                found = false;
                break;
            }
        }
        if (found){
            for (int _ = 0; _ < n / f; _++){
                cout << ans;
            }
            cout << '\n';
            return;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}