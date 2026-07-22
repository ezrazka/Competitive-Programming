#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0, r = 1e9, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;

        int f_mid2 = 0; // f(mid)
        for (int i = 0; i < n; i++) {
            f_mid2 += abs(a[i] - mid);
        }
        int f_mid1 = 0; // f(mid - 1)
        for (int i = 0; i < n; i++) {
            f_mid1 += abs(a[i] - (mid - 1));
        }
        
        // apakah f(mid) - f(mid - 1) < 0
        if (f_mid2 - f_mid1 < 0) { // (mid - 1, mid) fungsi f sedang turun
            l = mid + 1;
            ans = f_mid2;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
}