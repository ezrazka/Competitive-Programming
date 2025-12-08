#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        while (a[i] % 2 == 0) a[i] /= 2;
    };
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        while (b[i] % 2 == 0) b[i] /= 2;
    };
    sort(a.rbegin(), a.rend());

    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        freq[b[i]]++;
    }

    for (int i = 0; i < n; i++){
        if (i == 0 || __lg(a[i - 1]) > __lg(a[i])){
            map<int, int> new_freq;
            for (auto [key, val] : freq){
                int new_key = key;
                while (__lg(new_key) > __lg(a[i])){
                    new_key /= 2;
                }
                new_freq[new_key] += val;
            }
            swap(freq, new_freq);
        }
        if (freq.find(a[i]) != freq.end()){
            freq[a[i]]--;
            if (freq[a[i]] == 0){
                freq.erase(a[i]);
            }
        } else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}