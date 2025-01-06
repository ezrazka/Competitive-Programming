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
    int target, target_at;
    if (x + y + z > 1) target = 0;
    else target = 1;
    if (x == target) target_at = 1;
    else if (y == target) target_at = 2;
    else if (z == target) target_at = 3;
    else target_at = 4;

    if (target == 1){ // honest, therefore k > n / 4
        int l = c + 1, r = n - 1, res;
        while (l <= r){
            int mid = (l + r) / 2;

            int x = (target_at - 1) * c + 1, y = x + mid - 1;
            if (y > n){
                x -= y - n;
                y -= y - n;
            }

            if (query(x, y) == 1){
                l = mid + 1;
            } else {
                r = mid - 1;
                res = mid;
            }
        }
        answer(res);
    } else { // lie, therefore k <= n / 4
        int l = 2, r = n / 4, res;
        while (l <= r){
            int mid = (l + r) / 2;

            int x = 1, y = x + mid - 1;
            if (target_at == 1){
                x += c;
                y += c;
            }

            if (query(x, y) == 0){
                l = mid + 1;
            } else {
                r = mid - 1;
                res = mid;
            }
        }
        answer(res);
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