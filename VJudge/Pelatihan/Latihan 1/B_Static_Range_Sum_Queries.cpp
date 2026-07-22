#include <bits/stdc++.h>
using namespace std;

int main() {
    // int n;
    // int q;
    int n, q;
    // cin >> n;
    // cin >> q;
    cin >> n >> q;
    vector<int> x(n);
    for (int i = 0; i < n; i++){
        cin >> x[i];
    }

    vector<long long> pref(n + 1);
    // pref[i] -> jumlah dari i elemen pertama
    // pref[0] = jumlah {} -> 0
    // pref[1] = jumlah {x[0]} -> x[0]
    // pref[2] = jumlah {x[0], x[1]} -> x[0] + x[1]
    // pref[3] = jumlah {x[0], x[1], x[2]} -> x[0] + x[1] + x[2]
    // ...
    pref[0] = 0;
    for (int i = 0; i < n; i++){
        // daripada menghitung dari awal,
        // kita bisa menggunakan ulang jumlah sebelumnya
        pref[i + 1] = pref[i] + x[i];
    }

    // x: 3 2 4 5 1 1 5 3
    // pref: 0 3 5 9 14 15 16 21 24

    for (int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r; //  1 to 3
        l--;
        r--;
        // Cara "Naive"
        // int jumlah = 0;
        // for (int j = l; j <= r; j++){
        //     jumlah += x[j];
        // }
        // cout << jumlah << endl;
        // O(n)
        cout << pref[r + 1] - pref[l] << endl; // O(1)
    }

    // Naive: O(n * q)
    // Optimized (Prefix Sum): O(n + q)
}