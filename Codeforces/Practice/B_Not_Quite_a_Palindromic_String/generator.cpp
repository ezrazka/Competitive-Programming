#include <bits/stdc++.h>
using namespace std;

#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int r) { uniform_int_distribution<int> dist(1, r); return dist(rng); }
int rand(int l, int r) { uniform_int_distribution<int> dist(l, r); return dist(rng); }

void solve(){
    int t = 1;
    int n = 2 * rand(5);
    int k = rand(n / 2);
    string s = "";
    for (int i = 0; i < n; i++){
        s += '0' + rand(0, 1);
    }

    cout << t << '\n';
    cout << n << ' ' << k << '\n';
    cout << s << '\n';
}

signed main(signed argc, char* argv[]){
    int seed = stoll(argv[1]);
    rng.seed(seed);
    solve();
}