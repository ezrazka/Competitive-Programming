#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, q; cin >> n >> q;
    string s; cin >> s;

    int sum = 0, empty = 0, good_i = 0, maybe_good_i = 0, good_non_i = 0, good_i_non_i = 0;
    for (int i = 0, last_maybe = -2; i < n; i++){
        if (s[i] == '?'){
            empty++;
            if (
                (i + 1 < n && (s[i + 1] == 'V' || s[i + 1] == 'X')) &&
                (i - 1 < 0 || s[i - 1] != 'I')
            ) good_i++;
            if (
                i - last_maybe >= 2 &&
                (i + 1 < n && s[i + 1] == '?') &&
                (i - 1 < 0 || s[i - 1] != 'I') &&
                (i + 2 >= n || s[i + 2] != 'V' && s[i + 2] != 'X')
            ) maybe_good_i++, last_maybe = i;
        } else {
            if (s[i] == 'I' && (i + 1 < n && (s[i + 1] == 'V' || s[i + 1] == 'X'))) sum += -1;
            else if (s[i] == 'I') sum += 1;
            else if (s[i] == 'V') sum += 5;
            else sum += 10;
            if (
                s[i] == 'I' &&
                (i + 1 < n && s[i + 1] == '?') &&
                (i + 2 >= n || s[i + 2] != 'V' && s[i + 2] != 'X')
            ) good_non_i++;
            if (
                s[i] == 'I' &&
                (i + 1 < n && s[i + 1] == '?') &&
                (i + 2 < n && (s[i + 2] == 'V' || s[i + 2] == 'X'))
            ) good_i_non_i++;
        }
    }

    while (q--){
        int cx, cv, ci; cin >> cx >> cv >> ci;
        {
            if (ci >= empty) ci = empty, cv = 0, cx = 0;
            if (ci + cv >= empty) cv = empty - ci, cx = 0;
            if (ci + cv + cx >= empty) cx = empty - ci - cv;
        }
        int cur_sum = sum + (ci + cv * 5 + cx * 10);
        int a = ci, b = cv + cx;
        {
            int x = min(a, good_i);
            cur_sum += 2 * -1 * x;
            a -= x;
        }
        {
            int x = min(b, good_non_i);
            cur_sum += 2 * -1 * x;
            b -= x;
        }
        {
            int x = min(a + b, good_i_non_i);
            cur_sum += 2 * -1 * x;
            if (x <= abs(a - b)){
                if (a >= b) a -= x;
                else b -= x;
            } else {
                x -= abs(a - b);
                a = min(a, b);
                b = min(a, b);
                a -= x / 2;
                b -= (x + 1) / 2;
            }
        }
        {
            int x = min({a, b, maybe_good_i});
            cur_sum += 2 * -1 * x;
            a -= x;
            b -= x;
        }
        // debug(sum);
        // debug(good_i);
        // debug(good_non_i);
        // debug(maybe_good_i);
        // cout << ci << ' ' << cv << ' ' << cx << '\n';
        cout << cur_sum << '\n';
        /*
        3 priorities:
            1. take as many good_i as possible
                s[i] == '?' && s[i + 1] == 'V'/'X'
            2. take as many good_non_i as possible (must not intersect with 1)
                s[i] == 'I' && s[i + 1] == '?' && s[i + 2] != 'V'/'X'
            3. take as many maybe_good_i as possible (must not intersect with 1 and 2)
                s[i] == '?' && s[i + 1] == '?' && s[i - 1] != 'I' && s[i + 2] != 'V'/'X'
        */
    }

    /*
    we should avoid adding 'v' if we have 'i'
    we should avoid adding 'x' if we have 'v'
    but if were going to have 'v' and 'x', ideally we should put an 'i' before them
    the answer is the minimum sum in general, subtracted by 2 * {'i's who are before non-'i's}
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