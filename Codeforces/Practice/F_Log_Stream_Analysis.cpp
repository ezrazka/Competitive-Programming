#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int month_days[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void solve(){
    int n, m; cin >> n >> m;

    vector<int> times;
    vector<pair<string, string>> v;
    string s, t;
    while (cin >> s >> t){
        t = t.substr(0, 8);
        v.emplace_back(s, t);
        {
            string temp;
            getline(cin, temp);
        }
        int month, date, hour, minute, second;
        month = stoi(s.substr(5, 2));
        date = stoi(s.substr(8, 2));
        hour = stoi(t.substr(0, 2));
        minute = stoi(t.substr(3, 2));
        second = stoi(t.substr(6, 2));

        int total_seconds = (
            second +
            60 * minute +
            60 * 60 * hour + 
            60 * 60 * 24 * date
        );
        for (int i = 0; i < month - 1; i++){
            total_seconds += 60 * 60 * 24 * month_days[i];
        }
        times.push_back(total_seconds);
    }

    queue<int> q;
    for (int i = 0; i < v.size(); i++){
        q.push(times[i]);
        while (!q.empty() && times[i] - q.front() >= n){
            q.pop();
        }
        if (q.size() >= m){
            cout << v[i].first << ' ' << v[i].second << '\n';
            return;
        }
    }

    cout << -1 << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}