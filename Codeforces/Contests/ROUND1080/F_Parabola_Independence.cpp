#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++){
        cin >> a[i] >> b[i] >> c[i];
    }

    vector<int> cnt(n, 1);
    vector<int> pos, neg;
    for (int i = 0; i < n; i++){
        if (a[i] > 0) pos.push_back(i);
        else neg.push_back(i);
    }
    sort(pos.begin(), pos.end(), [&](int i, int j){
        int D_i = b[i] * b[i] - 4ll * a[i] * c[i];
        int D_j = b[j] * b[j] - 4ll * a[j] * c[j];
        return -D_i * a[j] > -D_j * a[i];
    });
    sort(neg.begin(), neg.end(), [&](int i, int j){
        int D_i = b[i] * b[i] - 4ll * a[i] * c[i];
        int D_j = b[j] * b[j] - 4ll * a[j] * c[j];
        return -D_i * a[j] < -D_j * a[i];
    });

    auto intersects = [&](int i, int j){
        int aa = a[i] - a[j];
        int bb = b[i] - b[j];
        int cc = c[i] - c[j];

        if (aa == 0 && bb == 0){
            return false;
        }

        if (cc == 0){
            return true;
        }
        
        return bb * bb - 4ll * aa * cc >= 0;
    };

    for (int i = 0; i < pos.size(); i++){
        for (int j = 0; j < i; j++){
            if (!intersects(pos[i], pos[j])){
                cnt[pos[i]] = max(cnt[pos[i]], cnt[pos[j]] + 1);
            }
        }
    }

    for (int i = 0; i < neg.size(); i++){
        for (int j = 0; j < i; j++){
            if (!intersects(neg[i], neg[j])){
                cnt[neg[i]] = max(cnt[neg[i]], cnt[neg[j]] + 1);
            }
        }
    }
    
    vector<int> vans(n);
    for (int i = 0; i < n; i++){
        int cur = cnt[i];
        bool is_positive = find(pos.begin(), pos.end(), i) != pos.end();
        if (is_positive){
            for (int j : neg){
                if (!intersects(i, j)){
                    cur = max(cur, cnt[i] + cnt[j]);
                }
            }
        } else {
            for (int j : pos){
                if (!intersects(i, j)){
                    cur = max(cur, cnt[i] + cnt[j]);
                }
            }
        }
        vans[i] = cur;
    }

    for (int i = 0; i < pos.size(); i++){
        for (int j = 0; j < i; j++){
            if (!intersects(pos[i], pos[j])){
                vans[pos[j]] = max(vans[pos[j]], vans[pos[i]]);
            }
        }
    }

    for (int i = 0; i < neg.size(); i++){
        for (int j = 0; j < i; j++){
            if (!intersects(neg[i], neg[j])){
                vans[neg[j]] = max(vans[neg[j]], vans[neg[i]]);
            }
        }
    }

    for (int i = 0; i < n; i++){
        cout << vans[i] << " \n"[i == n - 1];
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}