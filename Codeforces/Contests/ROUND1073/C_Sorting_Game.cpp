#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    if (is_sorted(s.begin(), s.end())){
        cout << "Bob\n";
        return;
    }

    cout << "Alice\n";

    int l = 1, r = n;
    vector<int> vans;
    while (l <= r){
        int mid = (l + r) / 2;

        string temp(s);
        vector<int> v;
        for (int i = 0, cnt = 0; i < n && cnt < mid; i++){
            if (temp[i] == '1'){
                temp[i] = '0';
                cnt++;
                v.push_back(i);
            }
        }
        vector<int> w;
        for (int i = n - 1, cnt = 0; i >= 0 && cnt < mid; i--){
            if (temp[i] == '0'){
                temp[i] = '1';
                cnt++;
                w.push_back(i);
            }
        }

        if (!is_sorted(temp.begin(), temp.end())){
            l = mid + 1;
        } else {
            r = mid - 1;

            reverse(w.begin(), w.end());
            vans.clear();
            merge(
                v.begin(), v.end(),
                w.begin(), w.end(),
                back_inserter(vans)
            );
        }
    }

    cout << vans.size() << '\n';
    for (int i = 0; i < vans.size(); i++){
        cout << vans[i] + 1 << " \n"[i == vans.size() - 1];
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