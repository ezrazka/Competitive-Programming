#include <bits/stdc++.h>
using namespace std;

#define int long long
// semua keyword "int" diganti menjadi long long
// "alias" dari int: signed, int32_t, ...

int ans = 1e9; // 10^9

// vector<int> a -> membuat copy O(n)
// vector<int>& a -> membuat "reference" O(n) -> masukin alamatnya,
// gak perlu membuat copy, karena, kita tinggal intip nilainya yang ada pada alamat itu
// meletakkan & -> artinya kita masukin variabelnya langsung (bukan valuenya)
void hitung(vector<int>& a, int total_a, int index, int jumlah_himpunan_1) {
    // Base Case (kasus dimana rekursinya berhenti)
    if (index == a.size()) {
        int jumlah_himpunan_2 = total_a - jumlah_himpunan_1;
        ans = min(ans, abs(jumlah_himpunan_1 - jumlah_himpunan_2));
        return;
    }
    // Recursive Case (kasus dimana rekursinya lanjut)
    // ambil
    hitung(a, total_a, index + 1, jumlah_himpunan_1 + a[index]);
    // tidak ambil
    hitung(a, total_a, index + 1, jumlah_himpunan_1);
}

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int total_a = 0;
    for (int i = 0; i < a.size(); i++) {
        total_a += a[i];
    }

    hitung(a, total_a, 0, 0);

    cout << ans << endl;

    // menghitung semua kemungkinan |jumlah_himpunan_1 - jumlah_himpunan_2|
    // hitung semua kemungkinan jumlah_himpunan_1 dan jumlah_himpunan_2
}