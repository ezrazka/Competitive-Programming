#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;

    int l = 1, r = n * n, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;

        int banyak = 0; // banyak nilai <= mid
        // ... O(n)?
        // setiap barisan berbentuk kelipatan
        // untuk setiap baris, hitung banyak <= mid, dalam O(1)
        // contoh: 5, 10, 15, 20, 25, 30; berapa <= 23?
        // -> 23 / 5 -> 4
        for (int i = 1; i <= n; i++) {
            banyak += min(n, mid / i); // bisa saja melewati n, padahal setiap baris cuma n elemen
        }
        
        int indeks_median = (1 + n * n) / 2;
        // banyak >= indeks_median
        if (banyak < indeks_median) {
            l = mid + 1;
        } else {
            r = mid - 1;
            ans = mid;
        }
    }
    cout << ans << '\n';
    // 1 2 3
    // 2 4 6
    // 3 6 9
    // 1 2 2 3 3 4 6 6 9
    //         ^
}