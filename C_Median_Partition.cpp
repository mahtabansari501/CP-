#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int ans = 1;

        for (int m = 0; m < n; m++) {
            int x = a[m];

            // step 1: transform + prefix
            vector<int> pref(n + 1, 0);
            for (int i = 0; i < n; i++) {
                pref[i + 1] = pref[i] + (a[i] >= x ? 1 : -1);
            }

            // coordinate compression
            vector<int> vals = pref;
            sort(vals.begin(), vals.end());
            vals.erase(unique(vals.begin(), vals.end()), vals.end());

            int sz = vals.size();

            // dp
            vector<int> dp(n + 1, -1e9);
            dp[0] = 0;

            // best arrays
            vector<int> best_even(sz, -1e9), best_odd(sz, -1e9);

            int idx0 = lower_bound(vals.begin(), vals.end(), 0) - vals.begin();
            best_even[idx0] = 0;

            for (int i = 1; i <= n; i++) {
                int idx = lower_bound(vals.begin(), vals.end(), pref[i]) - vals.begin();

                int best = -1e9;

                // query all smaller prefix sums
                if (i % 2 == 0) {
                    for (int j = 0; j < idx; j++) {
                        best = max(best, best_odd[j]);
                    }
                } else {
                    for (int j = 0; j < idx; j++) {
                        best = max(best, best_even[j]);
                    }
                }

                if (best > -1e8) dp[i] = best + 1;

                // update
                if (i % 2 == 0) {
                    best_even[idx] = max(best_even[idx], dp[i]);
                } else {
                    best_odd[idx] = max(best_odd[idx], dp[i]);
                }
            }

            ans = max(ans, dp[n]);
        }

        cout << ans << '\n';
    }

    return 0;
}