#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int n; cin >> n;
    vector<int> freq(n + 1);
    int small = 0, big = 0;
    int cnt_big = 0;
    for (int i = 1; i <= n; i++) {
        cin >> freq[i];
        if (freq[i] == 1) small += freq[i];
        else big += freq[i], cnt_big++;
    }

    int quota = 0;
    for (int i = 1; i <= n; i++) {
        if (freq[i] == 1) continue;
        if (cnt_big == 1) quota += freq[i] / 2;
        else quota += (freq[i] - 2) / 2;
    }
    int ans = big + min(small, quota);
    cout << (ans >= 3 ? ans : 0) << '\n';


    /*
        BBBAABAA
        Case 1, ans1 is a multiple of 3: its just the triangle inequality thing
        Case 2, ans2 is ans1 + 1 or ans1 + 2: 

        lay down all >1 in order, interleave them with the 1s, except on boundaries
    */
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
