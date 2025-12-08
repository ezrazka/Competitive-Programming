#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<vector<pair<int, int>>> freqs;
    {
        freqs.push_back({});
        pair<int, int> cur = {a[0], 1};
        for (int i = 1; i < n; i++){
            if (cur.first == a[i]){
                cur.second++;
            } else {
                freqs.back().push_back(cur);
                cur = {a[i], 1};
            }
        }
        freqs.back().push_back(cur);
    }
    
    int temp = min(k, __lg(n) + __lg((int) 2e5) + 2);
    while (temp--){
        vector<vector<pair<int, int>>> nfreqs1;
        vector<vector<pair<int, int>>> nfreqs2;
        for (int x = 0; x < freqs.size(); x++){
            nfreqs1.push_back({});
            nfreqs2.push_back({});
            int cnt = 0;
            bool second_half = false;
            for (pair<int, int> cur : freqs[x]){
                cur.second *= 2;
                if (!second_half && cnt + cur.second >= n){
                    {
                        if (!nfreqs1.back().empty() && nfreqs1.back().back().first == cur.first){
                            nfreqs1.back().back().second += n - cnt;
                        } else {
                            nfreqs1.back().push_back({cur.first, n - cnt});
                        }
                        cur = {cur.first, cur.second - (n - cnt)};
                        cnt += n - cnt;
                    }
                    second_half = true;
                }
                if (cur.second == 0) continue;
                if (!second_half){
                    if (!nfreqs1.back().empty() && nfreqs1.back().back().first == cur.first){
                        nfreqs1.back().back().second += cur.second;
                    } else {
                        nfreqs1.back().push_back(cur);
                    }
                } else {
                    if (!nfreqs2.back().empty() && nfreqs2.back().back().first == cur.first){
                        nfreqs2.back().back().second += cur.second;
                    } else {
                        nfreqs2.back().push_back(cur);
                    }
                }
                cnt += cur.second;
            }
        }

        freqs.clear();
        for (int i = 0; i < nfreqs1.size(); i++){
            freqs.push_back(nfreqs1[i]);
            if (freqs.size() == (int) 2e5) break;
        }
        if (freqs.size() == (int) 2e5) continue;
        for (int i = 0; i < nfreqs2.size(); i++){
            freqs.push_back(nfreqs2[i]);
            if (freqs.size() == (int) 2e5) break;
        }
    }
    for (int i = 0; i < freqs.size(); i++){
        int sum = 0;
        for (auto [val, cnt] : freqs[i]){
            sum += val * cnt;
        }
        cout << sum << '\n';
    }
}