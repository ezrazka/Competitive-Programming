#include <bits/stdc++.h>
using namespace std; // tidak perlu std::

int main() {
    int testcases;
    cin >> testcases;
    for (int i = 0; i < testcases; i++) { // mengulang sebanyak `testcases` kali
        int a, b;
        cin >> a >> b; // input
        int jawaban = 1000000000; // jawaban
        for (int c = a; c <= b; c++) { // mengulang nilai [a, b]
            int perhitungan = (c - a) + (b - c); // non-negatif (>= 0)
            // if (perhitungan < jawaban) { // update jawaban (minimum so far)
            //     jawaban = perhitungan;
            // }
            jawaban = min(jawaban, perhitungan); // ekuivalen
        }
        cout << jawaban << endl;
    }
}