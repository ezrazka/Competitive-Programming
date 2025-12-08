#include <bits/stdc++.h>
using namespace std;

#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int randInt(int r) { uniform_int_distribution<int> dist(1, r); return dist(rng); }
int randInt(int l, int r) { uniform_int_distribution<int> dist(l, r); return dist(rng); }

void solve() {
    int t = 1;
    cout << t << "\n";

    // small brute sizes
    int N = randInt(0, 20);
    int M = N;

    cout << N << " " << M << "\n";

    vector<int> A(N+1), B(M+1);

    // generate monotone A
    int cur = randInt(0, 5);
    for (int i = 0; i <= N; i++) {
        cur += randInt(0, 5);  // nondecreasing
        A[i] = cur;
    }

    // generate monotone B
    cur = randInt(0, 5);
    for (int j = 0; j <= M; j++) {
        cur += randInt(0, 5);  // nondecreasing
        B[j] = cur;
    }

    for (int i = 0; i <= N; i++) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << "\n";

    for (int j = 0; j <= M; j++) {
        if (j) cout << " ";
        cout << B[j];
    }
    cout << "\n";
}

signed main(signed argc, char* argv[]) {
    int seed = stoll(argv[1]);
    rng.seed(seed);
    solve();
}
