#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // === NAIVE SOLUTION (Brute Force, O(n^2)) ===
    /*
    // Cari 2 indeks i, j dimana a[i] + a[j] == x
    for (int i = 0; i < n; i++) { // i = 6, j = 0, 1, 2, 3, 4, 5
        for (int j = 0; j < i; j++) {
            if (a[i] == a[j]) {
                cout << i + 1 << ' ' << j + 1 << endl;
                // +1 karena soalnya minta indeks "1-based" bukan "0-based"
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    */

    // === OPTIMIZED SOLUTION (std::map<>, O(n log n)) ===
    map<int, int> mp; // selalu menyimpan [0, i - 1] ketika diakses
    for (int i = 0; i < n; i++) { // O(n)
        int target = x - a[i];
        if (mp.count(target) > 0) { // O(log n)
            int j = mp[target];
            cout << i + 1 << ' ' << j + 1 << endl;
            return 0;
        }
        mp[a[i]] = i; // O(log n)
    }
    cout << "IMPOSSIBLE" << endl;

    /*
    3 Solutions Semuanya O(n log n) (dengan pengecualian)
        1. Sort + Two-Pointers O(n log n)
        2. Sort + Binary Search O(n log n)
        3. std::map<> O(n log n) -> technically kalo pake std::unordered_map<> O(n)
    */
}