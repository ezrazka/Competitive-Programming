#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

int query(int l, int r){
    cout << "? " << l << ' ' << r << endl;
    int x; cin >> x;
    return x;
}

void answer(int m){
    cout << "! " << m << endl;
}

void solve(){
    int n; cin >> n;

    int l = 1, r = n;


    /*
    if i get the whole sum, given i know k,
        i can determine how many of operation 2 has been done

    there must be a maximum of 16 max values

    if you split in two,
    the half with the larger sum contains the largest num

    1 1 1 1 4
    4 2 2 2 2

    4 1 1 1 1 2 2 2 2
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