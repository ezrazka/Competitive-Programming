#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

constexpr int INF = 1e18;

int triangle(int n){
    return n * (n + 1) / 2;
}

int inv(int a, int m){
    int x, y;
    function<int(int,int,int&,int&)> egcd =
    [&](int a,int b,int &x,int &y)->int{
        if(!b){ x=1; y=0; return a; }
        int x1,y1;
        int g=egcd(b,a%b,x1,y1);
        x=y1;
        y=x1-(a/b)*y1;
        return g;
    };
    egcd(a,m,x,y);
    return (x%m+m)%m;
}

void solve(){
    int m, a, b; cin >> m >> a >> b;
    int g = __gcd(a, b);
    int original_m = m;
    m /= g, a /= g, b /= g;
    int inv_b = inv(b % a, a);

    int k = 2 * a - 1;
    vector<vector<int>> sparse_table(k, vector<int>(__lg(k) + 1));
    sparse_table[0][0] = 0;
    for (int i = 1; i < k; i++){
        sparse_table[i][0] = (sparse_table[i - 1][0] + b) % a;
    }
    for (int bit = 1; bit <= __lg(k); bit++){
        for (int i = 0; i < k; i++){
            if (i + (1 << (bit - 1)) < k){
                sparse_table[i][bit] = max(
                    sparse_table[i][bit - 1],
                    sparse_table[i + (1 << (bit - 1))][bit - 1]
                );
            }
        }
    }

    vector<int> index(a);
    for (int i = 0; i < a; i++){
        index[sparse_table[i][0]] = i;
    }
    auto query = [&](int l, int r){
        int len = r - l + 1;
        return max(sparse_table[l][__lg(len)], sparse_table[r - (1 << __lg(len)) + 1][__lg(len)]);
    };

    vector<int> to_add(a + b - 1);
    int ans = (m >= a + b - 1 ? triangle(m + 1) - triangle(a + b - 1) : 0);
    int sum = 0;
    for (int i = 0; i < min(m + 1, a + b - 1); i++){
        int when_add = i;
        {
            int k = ((-i * inv_b) % a + a) % a;
            // for (int j = 0; j < k; j++){
            //     when_add = max(when_add, (i + b * j) % a + b);
            // }
            if (k >= 1){
                when_add = max(when_add, query(index[i % a], index[i % a] + k - 1) + b);
            }
        }
        if (when_add < a + b - 1){
            to_add[when_add]++;
        }
        sum += to_add[i];
        ans += sum;
    }
    cout << ans * g - ((m * g + g - 1) - original_m) * (m < a + b - 1 ? sum : m + 1) << '\n';
    /*
    given gcd(a, b) == 1,
    if you can reach numbers [0, a - 1], you can reach all numbers

    but you can only reach numbers that are a multiple of gcd(a, b)
    if you can reach numbers [0, a - gcd(a, b)], you can reach all multiple of gcd(a, b)
    to simplify, we can modify the input to make the problem identical (slightly modifying answer),
    but where gcd(a, b) == 1

    it can be proven that if gcd(a, b) == 1,
    for all i >= a + b - 1, f(i) = i + 1
    therefore we only need to manually calculate all i < a + b - 1
    this can be done by:
        for each index i, calculate when it will become reachable,
        when it does, add it to the sum
        this number becomes:
        max(i, max of (i + b * j) % a + b -> for 0 <= j < k)
        where:
        i + bk = 0 (mod a)
        k = -ib^(-1) (mod a), find k
        the latter can be calculated efficiently for variables (i % a, -ib^(-1) (mod a)) with a sparse table
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}