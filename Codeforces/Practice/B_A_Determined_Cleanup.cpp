#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int p, k; cin >> p >> k;

    if (p < k){
        cout << "1\n" << p << '\n';
        return;
    }

    vector<int> q;
    q.push_back(-(p / k));
    while (q.back() < 0 || q.back() >= k){
        int sign = -q.back() / abs(q.back());
        if (sign == 1){
            q.push_back((abs(q.back()) + k - 1) / k);
        } else {
            q.push_back(-(q.back() / k));
        }
    }

    vector<int> f(q.size() + 1);
    for (int i = 0; i < q.size(); i++){
        f[i + 1] += q[i] * 1;
        f[i] += q[i] * k;
    }
    f[0] += p;

    cout << f.size() << '\n';
    for (int i = 0; i < f.size(); i++){
        cout << f[i] << " \n"[i == f.size() - 1];
    }

    /*
        f(x) = q(x) * (x + k) + p
        f(-k) = p

        Observations:
        * if k >= p, polynomial is just: p
        * if q(x) = -x + -floor(p / k)
        
        -x * x
        -x * k
        -floor(p / k) * x
        -floor(p / k) * k

        -x^2 + (-k - floor(p / k))x + (-floor(p / k) * k)

        q(x) = ceil(floor(p / k) / k) - floor(p / k)
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}