#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MX = 2e5;

int pow(int bit){
    return (1ll << min(62ll, bit));
}

int sum(int bit){
    return (1ll << (bit + 1)) - 1;
}

int range_sum(int a, int b){
    return sum(b) - sum(a - 1);
}

int get_ans(vector<int> &pref, int k, int i){
    int n = pref.size() - 1;

    if (MX * MX <= pow(k)){
        return pref[]
    }

    int lb = ((i - 1) * n + pow(k) - 1) / pow(k);
    int ub = (i * n) / pow(k);
    
    int sum_left = (pref[lb] - pref[max(0ll, lb - 1)]) * (lb * pow(k) - (i - 1) * n);
    int sum_mid = (pref[ub] - pref[lb]) * pow(k);
    int sum_right = (pref[min(n, ub + 1)] - pref[ub]) * (i * n - ub * pow(k));

    return sum_left + sum_mid + sum_right;
    /*
    the chunk size: x = n / 2^k

    for i-th consecutive chunk (1..2^k):
    sum[((i - 1) * x)...(i * x)] * 2^k

    i * n / 2^k
    */
}

signed main(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++){
        pref[i] = pref[i - 1] + a[i - 1];
    }

    int mx = (k <= 17 ? (1ll << k) : MX);
    vector<int> order(mx);
    order[0] = 1;
    for (int i = 1; i < mx; i++){
        int lsb = __lg(i & -i);
        int difference = pow((k - 1) - lsb) - range_sum(k - lsb, k - 1);
        order[i] = order[i - 1] + difference;
    }

    for (int i = 0; i < mx; i++){
        cout << get_ans(pref, k, order[i]) << '\n';
    }

    /*
    the chunk size: x = n / 2^k

    for i-th consecutive chunk (1..2^k):
    sum[((i - 1) * x)...(i * x)] * 2^k

    --------

    problem: the ordering is not consecutive

    for k = 1: order = 1, 2 (+1)
    for k = 2: order = 1, 3, 2, 4 (+2, -1, +2)
    for k = 3: order = 1, 5, 3, 7, 2, 6, 4, 8 (+4, -2, +4, -5, +4, -2, +4)
    -> old difference, -= 2^(k - 1), new difference = 2^(k - 1)
    
    repeat this k times: O(2e5 * k)
    */
   cout << pow(1000) << '\n';
}