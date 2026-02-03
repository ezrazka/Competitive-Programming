#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int N = 5000;
vector<vector<int>> memo(N, vector<int>(N, -1));

int query(int i, int j){
    if (memo[i][j] != -1){
        return memo[i][j];
    }
    cout << "? " << i << ' ' << j << endl;
    int x; cin >> x;
    return memo[i][j] = x;
}

void answer(int answer_cnt, vector<int> p){
    cout << "!\n";
    cout << answer_cnt << '\n';
    for (int i = 0; i < p.size(); i++){
        cout << p[i] << " \n"[i == p.size() - 1];
    }
    cout << flush;
}

void solve(){
    int n; cin >> n;

    int answer_cnt = 0;
    vector<int> ans(n), p(n), b(n);
    for (int p0 = 0; p0 < n; p0++){
        p[0] = p0;
        b[0] = p[0] ^ query(0, 0);
        for (int i = 1; i < n; i++){
            p[i] = b[0] ^ query(i, 0);
            b[i] = p[0] ^ query(0, i);
        }
        
        bool ok = true;
        for (int i = 0; i < n; i++){
            if (p[i] >= n || b[i] >= n || p[b[i]] != i){
                ok = false;
                break;
            }
        }

        if (ok) {
            if (answer_cnt == 0){
                copy(p.begin(), p.end(), ans.begin());
            }
            answer_cnt++;
        }
    }

    answer(answer_cnt, ans);
    /*
    we can brute force the first element, and deduce all other 2n - 1 elements with queries

    2 0 1 3
    1 2 0 3

    3 1 2 0
    0 2 1 3
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