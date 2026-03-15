#include <bits/stdc++.h> // import hampir semua library
// #include <iostream>
using namespace std;

int main() {
    // Menghitung jumlah elemen unik dalam sebuah array
    int n;
    cin >> n;
    // int x[n]; // array primitif
    vector<int> x(n); // vector
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    } // ✅

    set<int> setku;
    for (int i = 0; i < n; i++) {
        setku.insert(x[i]);
    }
    cout << setku.size() << endl;
}