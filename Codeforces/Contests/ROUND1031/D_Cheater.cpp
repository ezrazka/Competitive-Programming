#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

int calc(const vector<int>& a, const vector<int>& b){
    int n = a.size();
    int res = 0;
    int i = 0, j = 0;
    for (int _ = 0; _ < n; _++){
        if (a[i] > b[j]) i++, res++;
        else j++;
    }
    return res;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> b(n); for (int i = 0; i < n; i++) cin >> b[i];

    vector<int> pref_min(n);
    pref_min[0] = 0;
    for (int i = 1; i < n; i++){
        pref_min[i] = pref_min[i - 1];
        if (a[i] < a[pref_min[i]]){
            pref_min[i] = i;
        }
    }
    
    vector<int> suff_max(n);
    suff_max[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; i--){
        suff_max[i] = suff_max[i + 1];
        if (a[i] > a[suff_max[i]]){
            suff_max[i] = i;
        }
    }

    int l = calc(a, b), r = n;
    while (r - l >= 2){
        int mid = (l + r) / 2;
        
        swap(a[pref_min[mid - 1]], a[suff_max[mid]]);
        if (calc(a, b) >= mid){
            l = mid;
        } else {
            r = mid;
        }
        swap(a[pref_min[mid - 1]], a[suff_max[mid]]);
    }
    cout << l << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}