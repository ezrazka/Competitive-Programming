#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

struct LiChao {
    static const long long INF = (1LL << 60);
    int N;
    struct Line {
        long long m, b;
        Line(long long _m = 0, long long _b = -INF) : m(_m), b(_b) {}
        long long get(long long x) const { return m * x + b; }
    };

    vector<Line> seg;

    LiChao(int n) : N(n) {
        seg.assign(4*n + 5, Line());
    }

    void add_line(Line nw, int v, int l, int r) {
        int m = (l + r) >> 1;
        bool lef = nw.get(l) > seg[v].get(l);
        bool mid = nw.get(m) > seg[v].get(m);

        if (mid) swap(nw, seg[v]);

        if (l + 1 == r) return;
        else if (lef != mid) add_line(nw, v<<1, l, m);
        else                 add_line(nw, v<<1|1, m, r);
    }

    void add_segment(Line nw, int ql, int qr, int v, int l, int r) {
        if (qr <= l || r <= ql) return;
        if (ql <= l && r <= qr) {
            add_line(nw, v, l, r);
            return;
        }
        int m = (l + r) >> 1;
        add_segment(nw, ql, qr, v<<1, l, m);
        add_segment(nw, ql, qr, v<<1|1, m, r);
    }

    long long query(int x, int v, int l, int r) {
        long long res = seg[v].get(x);
        if (l + 1 == r) return res;
        int m = (l + r) >> 1;
        if (x < m) return max(res, query(x, v<<1, l, m));
        else       return max(res, query(x, v<<1|1, m, r));
    }

    long long query(int x) {
        return query(x, 1, 0, N);
    }
};

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    auto clamp = [&](int x){
        return max(0ll, min(n, x));
    };

    vector<int> left(n + 1);
    {
        stack<int> st;
        for (int i = 1; i <= n; i++){
            while (!st.empty() && a[i] <= a[st.top()]){
                st.pop();
            }
            left[i] = (st.empty() ? 1 : st.top() + 1);
            st.push(i);
        }
    }
    vector<int> right(n + 1);
    {
        stack<int> st;
        for (int i = n; i >= 1; i--){
            while (!st.empty() && a[i] <= a[st.top()]){
                st.pop();
            }
            right[i] = (st.empty() ? n : st.top() - 1);
            st.push(i);
        }
    }

    LiChao lc(n + 1);
    for (int i = 1; i <= n; i++){
        int x1 = left[i] - k;
        int x2 = min(left[i], right[i] - k + 1);
        int x3 = max(left[i], right[i] - k + 1);
        int x4 = right[i] + 1;
        int max_val = min(k, right[i] - left[i] + 1) * a[i];
        
        { /* Line 1 */
            int m = a[i]; // increments by a[i]
            int b = -m * x1; // 0 at x1
            lc.add_segment({m, b}, clamp(x1), clamp(x2) + 1, 1, 0, n + 1);
        }
        { /* Line 2 */
            int m = 0; // horizontal line
            int b = max_val; // never changes
            lc.add_segment({m, b}, clamp(x2), clamp(x3) + 1, 1, 0, n + 1);
        }
        { /* Line 3 */
            int m = -a[i]; // decrements by a[i]
            int b = max_val - m * x3; // max_val at x3
            lc.add_segment({m, b}, clamp(x3), clamp(x4) + 1, 1, 0, n + 1);
        }
    }

    for (int i = 1; i <= n - k + 1; i++){
        cout << lc.query(i) << " \n"[i == n - k + 1];
    }

    /*
        every N rectangle contribution is shaped like
                     _____________
                    /             \
                   /               \
                  /                 \
            left[i] - k         right[i] + k
        so we can simply add 3 line segments for each index,
        then query the maximum line y-coordinate for each sliding window index
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