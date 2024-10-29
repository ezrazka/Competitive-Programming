#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    cout << "TANYA 128" << endl;
    for (int i = 1; i <= 128; i++){
        cout << i << ' ';
    }
    cout << endl;

    int x; cin >> x;

    if (x != 0){
        cout << "TANYA 129" << endl;
        for (int i = 1; i <= 129; i++){
            cout << i << ' ';
        }
        cout << endl;

        int y; cin >> y;

        if (x == y){
            cout << "JAWAB " << 257 - x << endl;
        } else {
            cout << "JAWAB " << 128 + x << endl;
        }
    } else {
        cout << "TANYA 128" << endl;
        for (int i = 129; i <= 256; i++){
            cout << i << ' ';
        }
        cout << endl;

        int x; cin >> x;

        cout << "TANYA 129" << endl;
        for (int i = 128; i <= 256; i++){
            cout << i << ' ';
        }
        cout << endl;

        int y; cin >> y;

        if (x == y){
            cout << "JAWAB " << x << endl;
        } else {
            cout << "JAWAB " << 129 - x << endl;
        }
    }
}

signed main(){
    // ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}