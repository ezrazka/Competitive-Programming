#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

int query(vector<int> v){
    cout << "? ";
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << ' ';
    }
    cout << endl;
    int x; cin >> x;
    return x;
}

void answer(string s){
    cout << "! " << s << endl;
}

int find_open_bracket_index(int n){
    {
        vector<int> v;
        for (int i = 1; i <= n; i++) v.push_back(i);
        int q = query(v);
        if (q == 0) return n;
    }
    int l = 1, r = n;
    while (r - l > 1){
        int mid = (l + r) / 2;
        
        vector<int> v;
        for (int i = l; i <= mid; i++) v.push_back(i);
        int q = query(v);

        if (q == 0){
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

void solve(){
    int n; cin >> n;
    int open_bracket_index = find_open_bracket_index(n);
    
    // do the binary trick thing
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}