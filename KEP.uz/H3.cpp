#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

vector<int> things = {28, 10, 12, 12, 30};
vector<int> things2 = {30, 12, 12, 10, 28};

void encrypt(){
    int n; cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<int> lexico(99);
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        lexico[stoi(v[i].substr(1, 2)) - 1]++;
        for (int j = 0; j < 5; j++){
            nums[i] *= things[j];
            nums[i] += stoi(v[i].substr(3 + 2 * j, 2)) - 1;
        }
    }

    string res;
    for (int num = 0; num < 99; num++){
        for (int i = 0; i < 16; i++){
            if (lexico[num] & (1ll << i)){
                res += '1';
            } else {
                res += '0';
            }
        }
    }
    for (int num : nums){
        for (int i = 0; i < 21; i++){
            if (num & (1ll << i)){
                res += '1';
            } else {
                res += '0';
            }
        }
    }
    cout << res << '\n';
}

void decrypt(){
    string bin; cin >> bin;

    cout << (bin.length() - 16 * 99) / 21 << '\n';
    vector<int> lexicos;
    for (int i = 0; i < 16 * 99; i += 16){
        int num = 0;
        for (int j = 0; j < 16; j++){
            num += (bin[i + j] - '0') * (1ll << j);
        }
        lexicos.push_back(num);
    }
    int ptr = 0;
    for (int i = 16 * 99; i < bin.length(); i += 21){
        int num = 0;
        for (int j = 0; j < 21; j++){
            num += (bin[i + j] - '0') * (1ll << j);
        }

        vector<int> stuff;
        for (int thing : things2){
            stuff.push_back(num % thing + 1);
            num /= thing;
        }
        reverse(stuff.begin(), stuff.end());

        cout << 'K';
        while (lexicos[ptr] == 0){
            ptr++;
        }
        lexicos[ptr]--;
        if (ptr + 1 < 10){
            cout << 0 << ptr + 1;
        } else {
            cout << ptr + 1;
        }
        for (int stuf : stuff){
            if (stuf < 10){
                cout << 0 << stuf;
            } else {
                cout << stuf;
            }
        }
        cout << '\n';
    }
}

void solve(){
    int tc; cin >> tc;
    if (tc == 1){
        encrypt();
    } else {
        decrypt();
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