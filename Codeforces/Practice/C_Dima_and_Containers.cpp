#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<int> a;
    while (n > 0){
        int x;
        {
            while (n > 0){
                cin >> x;
                n--;
                if (x == 0){
                    break;
                }
                a.push_back(x);
            }
        }
        if (x == 0){
            int m = a.size();
            vector<int> ord(m);
            iota(ord.begin(), ord.end(), 0);
            sort(ord.begin(), ord.end(), [&](int i, int j){
                return a[i] > a[j];
            });

            for (int i = 0; i < m; i++){
                if (m >= 1 && i == ord[0]) cout << "pushStack\n";
                else if (m >= 2 && i == ord[1]) cout << "pushQueue\n";
                else if (m >= 3 && i == ord[2]) cout << "pushBack\n";
                else cout << "pushFront\n";
            }
            
            vector<string> vans;
            if (m >= 1) vans.push_back("popStack");
            if (m >= 2) vans.push_back("popQueue");
            if (m >= 3) vans.push_back("popBack");
            
            if (vans.size() == 0){
                cout << "0\n";
            } else {
                cout << vans.size() << ' ';
                for (int i = 0; i < vans.size(); i++){
                    cout << vans[i] << " \n"[i == vans.size() - 1];
                }
            }
            vans.clear();
            a.clear();
        } else {
            int m = a.size();
            for (int i = 0; i < m; i++){
                cout << "pushFront\n";
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}