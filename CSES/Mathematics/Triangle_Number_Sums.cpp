#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

int last_k(int n){
    return (-1 + sqrtl(8 * n + 1)) / 2;
}
 
int is_1(int n){
    int k = last_k(n);
    return (k * (k + 1) / 2 == n);
}
 
int is_2(int n){
    for (int k = last_k(n / 2); k * (k + 1) / 2 < n; k++){
        if (is_1(n - k * (k + 1) / 2)) return true;
    }
    return false;
}
 
void solve(){
    int n; cin >> n;
 
    if (is_1(n)) cout << 1 << '\n';
    else if (is_2(n)) cout << 2 << '\n';
    else cout << 3 << '\n';
 
    // k * (k + 1) / 2 <= n
    // k^2 * k - 2n <= 0
    // (-1 +- sqrt(1^2 - 4 * 1 * (-2n)) )/ (2 * 1)
    // (-1 + sqrt(8n + 1)) / 2 >= k
    // k = floor((-1 + sqrt(8n + 1)) / 2) 
}
 
signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}