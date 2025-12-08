#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    bool start = false;
    vector<int> pref(n + 1);
    vector<int> pref2(n + 1);
    
    while (q--){
        int qq; cin >> qq;
        if (qq != 1 && !start){
            start = true;
            for (int i = 1; i <= n; i++){
                pref[i] = pref[i - 1] + a[i - 1];
            }
            for (int i = 1; i <= n; i++){
                pref2[i] = pref2[i - 1] + i * a[i - 1];
            }
        }
        if (qq == 1){
            int x; cin >> x;
            for (int i = 0; i < n; i++){
                if (i < (i ^ x)){
                    swap(a[i], a[i ^ x]);
                }
            }
        } else if (qq == 2){
            int l, r; cin >> l >> r; l++, r++;
            cout << pref[r] - pref[l - 1] << '\n';
        } else {
            int l, r; cin >> l >> r; l++, r++;
            cout << (pref2[r] - pref2[l - 1]) - (l - 1) * (pref[r] - pref[l - 1]) << '\n';
        }
    }
    /*
    0 xor 5 = 5 (1)
    1 xor 5 = 4 (0)
    2 xor 5 = 7 (3)
    3 xor 5 = 6 (2)

    0 xor 6 = 6 (2)
    1 xor 6 = 7 (3)
    2 xor 6 = 4 (0)
    3 xor 6 = 5 (1)

    0 xor 9 = 9
    1 xor 9 = 8
    2 xor 9 = 11
    3 xor 9 = 10
    4 xor 9 = 13
    5 xor 9 = 12
    6 xor 9 = 15
    7 xor 9 = 14

    0 xor 11 = 11
    1 xor 11 = 10
    2 xor 11 = 9
    3 xor 11 = 8
    4 xor 11 = 15
    5 xor 11 = 14
    6 xor 11 = 13
    7 xor 11 = 12
    */
}