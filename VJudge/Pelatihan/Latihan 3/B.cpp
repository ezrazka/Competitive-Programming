#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(k);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < k; i++) cin >> b[i];

    // a = 1 2 1 2 1
    // a = 1 3 4 6 7 <- berubah jadi prefix sumnya
    for (int i = 1; i < n; i++) {
        a[i] += a[i - 1];
    }

    for (int i = 0; i < k; i++) {
        int l = 0, r = n - 1, ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;

            // b[i] >= a[mid], mid + 1
            if (b[i] >= a[mid]) {
                l = mid + 1;
                ans = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << ans << endl;
    }
    /*
    1, 1, 1, 1, ..., 0, 0, 0
    */
}