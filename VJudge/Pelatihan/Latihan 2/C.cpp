#include <bits/stdc++.h>
using namespace std; // tidak perlu std::

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int durasi, deadline;
        cin >> durasi >> deadline;
        a[i] = {durasi, deadline};
    }
    sort(a.begin(), a.end()); // mengurutkan berdasar durasi paling kecil duluan
    // pair<int, int> kalo di sort, itu selalu mengutama elemen pertama dalam pair
    // (durasi, deadline) -> mengurutkan berdasarkan durasi

    long long hadiah = 0;
    for (int i = 0; i < n; i++) {
        int deadline = a[i].second;
        hadiah += deadline;
    }
    
    for (int i = 0; i < n; i++) {
        int durasi = a[i].first;
        int task_yang_tersisa = n - i;
        long long waktu_terulur = (long long) durasi * task_yang_tersisa;
        hadiah -= waktu_terulur;
    }
    cout << hadiah << endl;
    // strategi greedy kita, adalah memprioritaskan durasi terkecil
    // supaya dia mengulur waktu ke tugas-tugas yang tersisa sekecil mungkin
    /*
    durasi =a[i].first;
    mengurutkan berdasarkan durasi, kita memprioritaskan durasi terkecil
    */
}