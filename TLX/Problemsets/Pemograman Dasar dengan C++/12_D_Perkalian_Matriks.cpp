#include <bits/stdc++.h>
using namespace std;

int n, m, p;
int a[100][100], b[100][100], c[100][100];

int get_int(){
    int r = 0; bool neg = false; char c;
    while (1){
        c = getchar_unlocked();
        if (c == ' ' || c == '\n') continue;
        if (c == '-') { neg = true; continue; }
        else if (c < '0' || c > '9') continue;
        else break;
    }
    r = c - '0';
    while (1){
        c = getchar_unlocked();
        if (c >= '0' && c <= '9') r = (r << 3) + (r << 1) + (c - '0');
        else break;
    }
    if (neg) r = -r;
    return r;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    n = get_int(), m = get_int(), p = get_int();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            a[i][j] = get_int();
        }
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < p; j++){
            b[j][i] = get_int();
        }
    }

    const int B = 64;
    for (int ii = 0; ii < n; ii += B){
        for (int jj = 0; jj < p; jj += B){
            for (int kk = 0; kk < m; kk += B){
                int i_end = min(ii + B, n);
                int j_end = min(jj + B, p);
                int k_end = min(kk + B, m);
                for (int i = ii; i < i_end; i++){
                    for (int j = jj; j < j_end; j++){
                        int sum = c[i][j];
                        for (int k = kk; k < k_end; k++){
                            sum += a[i][k] * b[j][k];
                        }
                        c[i][j] = sum;
                    }
                }

            }
        }
    }

    // ---- FASTEST OUTPUT FOR 100x100 ----
    std::string out;
    out.reserve(n * p * 6);  // ~ max 5 digits + space per number

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {

            int x = c[i][j];

            // handle negative
            if (x < 0) { 
                out.push_back('-'); 
                x = -x; 
            }

            // convert integer to chars (fast)
            char buf[12];
            int len = 0;

            do {
                buf[len++] = char('0' + x % 10);
                x /= 10;
            } while (x > 0);

            // reverse into output
            while (len--) out.push_back(buf[len]);

            out.push_back(' ');
        }
        out.push_back('\n');
    }

    // ONE syscall → fastest possible
    fwrite(out.c_str(), 1, out.size(), stdout);
}