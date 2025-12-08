#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL<<62);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    if (!(cin >> N >> M)) return 0;
    vector<ll> A(N+1), B(M+1);
    for (int i = 0; i <= N; ++i) cin >> A[i];
    for (int j = 0; j <= M; ++j) cin >> B[j];

    int K = N + M;
    // helper: compute earliest k where candidate b becomes <= candidate a
    auto intersect = [&](int a, int b) -> ll {
        // require a < b
        if (a >= b) return INF;
        int delta = b - a;
        int maxT = M - delta; // t in [0..maxT], where k = b + t
        if (maxT < 0) return INF; // no overlap
        ll need = A[b] - A[a];
        // D(t) = B[t+delta] - B[t] is nondecreasing if B is convex.
        // find smallest t with D(t) >= need
        int lo = 0, hi = maxT;
        while (lo < hi) {
            int mid = (lo + hi) >> 1;
            ll D = B[mid + delta] - B[mid];
            if (D >= need) hi = mid;
            else lo = mid + 1;
        }
        if (B[lo + delta] - B[lo] >= need) return (ll)b + lo;
        return INF;
    };

    deque<int> q;           // candidate indices i
    deque<ll> start;        // start[k] = first k where corresponding candidate is optimal
    for (int i = 0; i <= N; ++i) {
        // maintain lower envelope of functions f_i(k) = A[i] + B[k-i]
        // remove dominated candidates from back
        ll inter = INF;
        while (!q.empty()) {
            int a = q.back();
            inter = intersect(a, i);
            if (inter <= start.back()) {
                q.pop_back();
                start.pop_back();
            } else break;
        }
        if (q.empty()) {
            // candidate i can start being considered at k = i
            start.push_back(i);
        } else {
            // intersection is the first k where i becomes better than previous back
            if (inter == INF) start.push_back(INF);
            else start.push_back(max<ll>(inter, i));
        }
        q.push_back(i);
    }

    vector<ll> C(K+1, INF);
    for (int k = 0; k <= K; ++k) {
        // pop front candidates that don't cover k yet
        while (!q.empty() && start.front() > k) {
            // If the front candidate's start > k, there's no valid candidate yet (this can happen at small k)
            // But we should not remove it; instead break and leave C[k] = INF until some candidate starts.
            break;
        }
        // advance to candidate whose start <= k and next candidate's start > k
        while (start.size() >= 2 && start[1] <= k) {
            q.pop_front();
            start.pop_front();
        }
        if (!q.empty() && start.front() <= k) {
            int i = q.front();
            int t = k - i;
            if (0 <= t && t <= M) C[k] = min(C[k], A[i] + B[t]);
        }
        // It's possible no candidate currently valid (C[k] remains INF) — that's correct.
    }

    for (int k = 0; k <= K; ++k) {
        if (k) cout << ' ';
        cout << C[k];
    }
    cout << '\n';
    return 0;
}
