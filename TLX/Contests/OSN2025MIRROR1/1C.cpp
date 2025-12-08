#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int k = 6;
    int n = 6;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            v[i][j] = (i + j) % k + 1;
        }
    }

    {
        cout << n << endl;
        cout << "QUERY" << endl;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cout << v[i][j] << ' ';
            }
            cout << endl;
        }
    }
    {
        int s, m; cin >> s >> m;

        cout << "QUERY\n";
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (v[i][j] != s) v[i][j] = 0;
                else v[i][j] = ((i - j) % k + k) % k + 1;
                cout << v[i][j] << ' ';
            }
            cout << endl;
        }
    }
    {
        int s, m; cin >> s >> m;
        int cnt = 1;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (v[i][j] != s) v[i][j] = 0;
                else v[i][j] = cnt++;
                cout << v[i][j] << ' ';
            }
            cout << endl;
        }
    }
    {
        int s, m; cin >> s >> m;
        int cnt = 1;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (v[i][j] == s){
                    cout << "ANSWER" << endl;
                    cout << i + 1 << ' ' << j + 1 << endl;
                    return 0;
                }
            }
        }
    }
}