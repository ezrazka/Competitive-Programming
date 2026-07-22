#include <bits/stdc++.h>
using namespace std; // tidak perlu std::

int main() {
    string s;
    cin >> s;
    int n = s.length();

    sort(s.begin(), s.end()); // O(n log n)

    // O(n!)? jangan lupa
    // kita juga harus print s
    // dan s panjangnya n
    // =====
    vector<string> vec;
    do {
        vec.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    // =====
    // O(n!) * n = O(n * n!)

    cout << vec.size() << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }

    /*
    next_permutation()
    1. memajukan stringnya menjadi permutasi selanjutnya
    2. dia akan mengembalikan FALSE jika permutasinya sudah habis
    */

    /*
    do {
        // kode
    } while (...);
    ini akan selalu run MINIMAL 1 kali

    dan
    while (...) {
        // kode
    }
    bisa saja run 0 kali
    ```
    */
}