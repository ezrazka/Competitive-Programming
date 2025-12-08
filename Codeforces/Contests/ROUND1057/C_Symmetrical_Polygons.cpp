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
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    map<int, int, greater<int>> freq;
    for (int i = 0; i < n; i++){
        freq[v[i]]++;
    }

    priority_queue<pair<int, int>> pq;
    int even_sum = 0;
    for (auto [key, val] : freq){
        int even_cost = val / 2 * 2 * key;
        int odd_cost = val * key;
        pq.push({odd_cost - even_cost, key});
        even_sum += even_cost;
    }

    int ans = 0;
    for (auto [key, val] : freq){
        pair<int, int> best1, best2;
        {
            while (!pq.empty() && pq.top().second > key) pq.pop();
            best1 = (pq.empty() ? make_pair(0ll, -1ll) : pq.top());
            if (!pq.empty()) pq.pop();
            while (!pq.empty() && pq.top().second > key) pq.pop();
            best2 = (pq.empty() ? make_pair(0ll, -1ll) : pq.top());
            if (best1.second != -1) pq.push(best1);
        }
        if (2 * key < even_sum + best1.first + best2.first){
            ans = max(ans, even_sum + best1.first + best2.first);
        }
        even_sum -= val / 2 * 2 * key;
    }
    cout << ans << '\n';

    /*
    conditions:
    * 2 * mx < sum
    * all lines must appear an even amount of times, except at most 2 lines
    
    other than the mx, greedily we choose the largest ones, filling out even and odd

    fix largest element, iterate from the end
    assume we take all even
    store a priority queue of {opportunity cost of taking over the even case, element}
        for all odd frequencies
    move on to next iteration
    find max of all iterations (when 2 * mx < sum)
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