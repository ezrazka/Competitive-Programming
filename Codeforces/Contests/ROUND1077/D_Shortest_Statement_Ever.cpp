#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

constexpr int INF = 1e18;

void solve(){
    bool flipped = false;
    int x, y; cin >> x >> y;
    if (x < y) swap(x, y), flipped = true;

    pair<int, pair<int, int>> ans = {INF, {-1, -1}};
    { // maximize (p + q)
        int p = x;
        int q = 0;
        for (int bit = 1 << __lg(y); bit >= 1; bit >>= 1){
            if (!(y & bit)) continue;
            if (!(x & bit)) q |= bit;
            else {
                q |= (bit - 1) ^ (x & (bit - 1));
                break;
            }
        }
        ans = {(x - p) + (y - q), {p, q}};
    }
    { // minimize (p + q)
        {
            int p = x;
            int q = y;
            while (p & q){
                p += p & -p;
            }
            ans = min(ans, {(p - x) + (q - y), {p, q}});
        }
        {
            int p = x;
            int q = y;
            while (p & q){
                q += q & -q;
            }
            ans = min(ans, {(p - x) + (q - y), {p, q}});
        }
    }
    { // maximize (p - q), either remove all bits they share in p, or add to q until done
        int q = y;
        while (x & q){
            int p = x | ((1 << __lg(x & q)) - 1);
            p = p ^ (p & q);
            ans = min(ans, {(x - p) + (q - y), {p, q}});
            q += q & -q;
        }
        ans = min(ans, {(x - x) + (q - y), {x, q}});
    }
    { // minimize (p - q)
        int p = x;
        while (y & p){
            int q = y | ((1 << __lg(y & p)) - 1);
            q = q ^ (p & q);
            ans = min(ans, {(p - x) + (y - q), {p, q}});
            p += p & -p;
        }
        ans = min(ans, {(p - x) + (y - y), {p, y}});
    }

    /*
    |x - p| + |y - q| is minimized
    what if i divide into four cases?
    (x - p) + (y - q) -> (x + y) - (p + q), maximize p + q -> greedily activate bits
    (x - p) + (q - y) -> (x - y) - (p - q), maximize p - q -> check O(bits) q possibilities
    (p - x) + (y - q) -> (y - x) + (p - q), minimize p - q -> check O(bits) p possibilities
    (p - x) + (q - y) -> (-x - y) + (p + q), minimize p + q -> greedily deactivate bits
    lets also WLOG x >= y
    */
   if (flipped) swap(x, y), swap(ans.second.first, ans.second.second);
   cout << ans.second.first << ' ' << ans.second.second << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}