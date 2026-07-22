#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, n;
    cin >> x >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++){
        cin >> d[i];
    }

    // priority_queue<int> pq; // prioritas tertinggi = maximum
    priority_queue<int, vector<int>, greater<int>> pq; // minimum
    for (int i = 0; i < n; i++){
        pq.push(d[i]);
    }

    /*
    strategi kita;
    1. mencari 2 elemen terkecil dan membuangnya dari pq
    2. meletakkan jumlah 2 elemen tersebut ke dalam pq
    3. tambahkan jumlah 2 elemen tersebut ke jawaban
    (mengambil elemen terkecil selalu "greedy", dan kita bisa buktikan
    bahwa "greedy" adalah optimal)
    */
    long long ans = 0;
    while (pq.size() > 1){
        // 1.
        int a = pq.top(); // elemen terkecil
        pq.pop();
        int b = pq.top(); // elemen terkecil kedua
        pq.pop();
        // 2.
        pq.push(a + b);
        // 3.
        ans += a + b;
    }
    cout << ans << endl;
    /*
    d = {2 3 3}, ans = 0
    gabungin
    d = {5 3}, ans = 5
    gabungin
    d = {8}, ans = 13
    */
}