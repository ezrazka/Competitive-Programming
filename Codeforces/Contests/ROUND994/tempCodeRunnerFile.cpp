#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

int query(int a, int b){
    cout << "? " << a << ' ' << b << endl;
    int x; cin >> x;
    return x;
}

void answer(int a){
    cout << "! " << a << endl;
}

void solve(){
    int n; cin >> n;
    int c = n / 4;

    int x = query(1, c), y = query(c + 1, 2 * c), z = query(2 * c + 1, 3 * c);
    int target, l, r;
    if (x + y + z > 1){
        target = 0;
    } else {
        target = 1;
    }
    if (x == target){
        l = 1, r = c;
    } else if (y == target){
        l = c + 1, r = 2 * c;
    } else if (z == target){
        l = 2 * c + 1, r = 3 * c;
    } else {
        l = 3 * c + 1, 4 * c;
    }

    while (l < r){
        int mid = (l + r) / 2;

        int val;
        if (mid - c + 1 >= 1){
            val = query(mid - c + 1, mid);
        } else {
            val = 1 - query(mid + 1, mid + c);
        }

        if (val != target){
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    answer(l);
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}