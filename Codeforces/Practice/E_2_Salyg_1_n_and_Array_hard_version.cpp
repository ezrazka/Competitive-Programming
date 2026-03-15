#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

int query(int i){
    cout << "? " << i << endl;
    int x; cin >> x;
    return x;
}

void answer(int x){
    cout << "! " << x << endl;
}

void solve(){
    int n, k; cin >> n >> k;
    int ans = 0;
    for (int i = 1; i + k - 1 <= n; i += k){
        ans ^= query(i);
    }
    if (n % k != 0){
        ans ^= query(n - k + 1 - (n % k) / 2);
        ans ^= query(n - k + 1);
    }
    answer(ans);
    /*
    just read:
    n and k are even

    Case 1 (k > n / 2):
        solve k = 4, n = 6
        1 2 3 4 5 6
        4 3 2 1
            6 5 1 2

        k must be divisible by 2 * k - n
        or
        k must be divisible by 

        01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16
        =============================
        ========          ====================
        ========          ===========          ========
        10 09 08 07 06 05 16 15 14 13 12 11 01 02 03 04
        

    Case 2 (k <= n / 2):
        just adjust overflow on the last two queries

        queries <= 50

    Case 1:
    
    case: odd k {
        }
        case: even k {
        }
        
        a ^ b
        a ^ c
        b ^ c
        
        i must solve
        k > n / 2
        k <= n
        in 9 moves or less

        how do i solve
        k = 50
        n = 51
        ?
        [1, 50] -> 1..50
        [2, 51] -> 1..49 and 51
        50 51 1 2 3 4 ..
        [1, 50] -> 1..48 and 50..51
        [2, 51] -> 1..47 and 49..51

        1 2 3
        2 1 3 -> {1, 2}
        2 3 1 -> {1, 3}
        3 2 1 -> {2, 3};

        1 2 3 4 5 6
        =======
        1 2 3 4 5 6
            =======
        4 3 2 1 5 6
            =======
        4 3 6 5 1 2
          =======
        -> (1, 2, 3, 4, 5), (4, 5, 6, 7, 8), ()

        1 2 3
        -> (1, 2), (2, 3), (1, 3)
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}