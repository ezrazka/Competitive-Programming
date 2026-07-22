#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int tc;
    cin >> tc;
    // tc--; -> kurangi tc dengan 1
    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        // untuk setiap panjang batang kayu yang unik, ada berapa?
        // kita tau 1 <= a[i] <= 100
        vector<int> banyak_unik(101); // 0 - 100 (101 angka)
        for (int i = 0; i < n; i++) {
            int panjang_batang_kayu = a[i];
            banyak_unik[panjang_batang_kayu]++; // banyaknya akan bertambah satu untuk panjang itu
        }

        // banyak_unik[i] -> banyak batang kayu yang panjangnya i
        int ans = 0;
        for (int panjang_batang_kayu = 1; panjang_batang_kayu <= 100; panjang_batang_kayu++) {
            ans += banyak_unik[panjang_batang_kayu] / 3; // bagi 3 dan bulatkan ke bawah
            // 1 batang kayu -> 0 segitiga
            // 2 batang kayu -> 0 segitiga
            // 3 batang kayu -> 1 segitiga
            // 4 batang kayu -> 1 segitiga
            // 5 batang kayu -> 1 segitiga
            // 6 batang kayu -> 2 segitiga
        }

        cout << ans << endl;
    }
    // "secara greedy, kita selalu memilih untuk membangun segitiga"
    // for (int i = 0; i < tc; i++) {
    // }
}