#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<long long> A(N+1), B(M+1);
    for (int i = 0; i <= N; i++) cin >> A[i];
    for (int j = 0; j <= M; j++) cin >> B[j];

    int K = N + M;
    vector<long long> C(K+1, (1LL<<62));

    for (int k = 0; k <= K; k++) {
        int L = max(0, k - M);
        int R = min(N, k);
        for (int i = L; i <= R; i++) {
            C[k] = min(C[k], A[i] + B[k - i]);
        }
    }

    for (int k = 0; k <= K; k++) {
        if (k) cout << ' ';
        cout << C[k];
    }
    cout << '\n';

    return 0;
}
