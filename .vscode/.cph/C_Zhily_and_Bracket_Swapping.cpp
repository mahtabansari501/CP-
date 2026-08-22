#include <bits/stdc++.h>
using namespace std;

const int MOD = 51123987;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if (!(cin >> n)) return 0;
    string s;
    cin >> s;
    string s_prime = "";
    for (int i = 0; i < n; ++i) {
        if (i == 0 || s[i] != s[i - 1]) {
            s_prime += s[i];
        }
    }
    
    int m = s_prime.length();
    vector<vector<int>> nxt(m + 1, vector<int>(3, m + 1));
    for (int i = m - 1; i >= 0; --i) {
        for (int c = 0; c < 3; ++c) {
            nxt[i][c] = nxt[i + 1][c];
        }
        int c_idx = 0;
        if (s_prime[i] == 'r') c_idx = 0;
        else if (s_prime[i] == 'g') c_idx = 1;
        else if (s_prime[i] == 'b') c_idx = 2;
        
        nxt[i][c_idx] = i + 1;
    }
    int max_c = (n + 2) / 3;
    vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(max_c + 1, vector<int>(max_c + 1, 0)));

    auto char_to_idx = [](char c) {
        if (c == 'r') return 0;
        if (c == 'g') return 1;
        return 2;
    };
    for (int c = 0; c < 3; ++c) {
        int p = nxt[0][c];
        if (p <= m) {
            int cr = (c == 0 ? 1 : 0);
            int cg = (c == 1 ? 1 : 0);
            int cb = (c == 2 ? 1 : 0);
            if (cr <= max_c && cg <= max_c && cb <= max_c) {
                dp[p][cr][cg] = (dp[p][cr][cg] + 1) % MOD;
            }
        }
    }
    for (int len = 1; len < n; ++len) {
        vector<vector<vector<int>>> next_dp(m + 1, vector<vector<int>>(max_c + 1, vector<int>(max_c + 1, 0)));
        
        for (int pos = 1; pos <= m; ++pos) {
            int curr_c = char_to_idx(s_prime[pos - 1]);
            
            for (int cr = 0; cr <= max_c; ++cr) {
                for (int cg = 0; cg <= max_c; ++cg) {
                    int cb = len - cr - cg;
                    if (cb < 0 || cb > max_c) continue;
                    
                    int val = dp[pos][cr][cg];
                    if (val == 0) continue;
                    for (int nxt_c = 0; nxt_c < 3; ++nxt_c) {
                        int ncr = cr + (nxt_c == 0 ? 1 : 0);
                        int ncg = cg + (nxt_c == 1 ? 1 : 0);
                        int ncb = cb + (nxt_c == 2 ? 1 : 0);
                        if (ncr > max_c || ncg > max_c || ncb > max_c) continue;

                        if (nxt_c == curr_c) {
                            next_dp[pos][ncr][ncg] = (next_dp[pos][ncr][ncg] + val) % MOD;
                        } else {
                            int npos = nxt[pos][nxt_c];
                            if (npos <= m) {
                                next_dp[npos][ncr][ncg] = (next_dp[npos][ncr][ncg] + val) % MOD;
                            }
                        }
                    }
                }
            }
        }
        dp = move(next_dp);
    }
    long long ans = 0;
    for (int pos = 1; pos <= m; ++pos) {
        for (int cr = 0; cr <= max_c; ++cr) {
            for (int cg = 0; cg <= max_c; ++cg) {
                int cb = n - cr - cg;
                if (cb < 0 || cb > max_c) continue;
                if (abs(cr - cg) <= 1 && abs(cg - cb) <= 1 && abs(cr - cb) <= 1) {
                    ans = (ans + dp[pos][cr][cg]) % MOD;
                }
            }
        }
    }

    cout << ans << endl;
}