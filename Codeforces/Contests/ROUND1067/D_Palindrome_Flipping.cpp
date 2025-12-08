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
    string s, t; cin >> s >> t;

    bool goods = false, goodt = false;
    for (int i = 0; i < n - 1; i++){
        if (s[i] == s[i + 1]) goods = true;
        if (t[i] == t[i + 1]) goodt = true;
    }

    vector<pair<int, int>> front;
    vector<pair<int, int>> back;

    if (!goods){
        front.push_back({0, 2});
        s[0] ^= 1, s[1] ^= 1, s[2] ^= 1;
    }
    if (!goodt){
        back.push_back({0, 2});
        t[0] ^= 1, t[1] ^= 1, t[2] ^= 1;
    }

    {
        while (s != string(n, '0')){
            int best = -1;
            pair<int, int> bestp = {-1, -1};
            for (int i = 0, j = 0; i < n; i++){
                while (s[i] == s[j] && j < n) j++;
                if (j - i > best){
                    best = j - i;
                    bestp = {i, j - 1};
                }
            }
            for (int i = bestp.first; i <= bestp.second; i++){
                s[i] ^= 1;
            }
            front.push_back(bestp);
        }
    }
    {
        while (t != string(n, '0')){
            int best = -1;
            pair<int, int> bestp = {-1, -1};
            for (int i = 0, j = 0; i < n; i++){
                while (t[i] == t[j] && j < n) j++;
                if (j - i > best){
                    best = j - i;
                    bestp = {i, j - 1};
                }
            }
            for (int i = bestp.first; i <= bestp.second; i++){
                t[i] ^= 1;
            }
            back.push_back(bestp);
        }
    }

    cout << front.size() + back.size() << '\n';
    for (int i = 0; i < front.size(); i++){
        cout << front[i].first + 1 << ' ' << front[i].second + 1 << '\n';
    }
    for (int i = 0; i < back.size(); i++){
        cout << back[back.size() - 1 - i].first + 1 << ' ' << back[back.size() - 1 - i].second + 1 << '\n';
    }

    /*
    case 1:
        if t has at least 1 s[i] == s[i + 1], possible
    case 2:
        t is odd: 1010101
        t is even: 101010


    10111
    10101

    1001
    1010

    0110000
    0101010
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}