#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;

    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i = 0; i < n; i += 2){
        for (int j = 0; j < n; j++){
            a[i][j] = (1ll << (i + j));
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << a[i][j] << " \n"[j == n - 1];
        }
    }
    cout << flush;

    int q; cin >> q;
    while (q--){
        int k; cin >> k;

        int r = 0, c = 0;
        cout << r + 1 << ' ' << c + 1 << '\n';
        while (r < n - 1 || c < n - 1){
            // if match, go there
            // if none match, go zero
            if (r + 1 < n && (k & a[r + 1][c])) r++;
            else if (c + 1 < n && (k & a[r][c + 1])) c++;
            else if (c == n - 1 || r + 1 < n && a[r + 1][c] == 0) r++;
            else c++;
            cout << r + 1 << ' ' << c + 1 << '\n';
        }
        cout << flush;
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
/*
00 01 03 06 08
02 04 07 09 11
03 06 08 10 12
07 09 11 13 15
08 10 12 14 00

00 01 02 03 04
00 00 00 00 00
02 03 04 05 06
00 00 00 00 00
04 05 06 07 08
*/