#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0, r = 1e6, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        // jumlah jika kita memilih x = mid

        long long jumlah = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > mid) jumlah += a[i] - mid;
        }

        if (jumlah >= m) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    /*
    1, 1, 1, 1, 1, ..., 0, 0, 0
    */
    cout << ans << endl;
}