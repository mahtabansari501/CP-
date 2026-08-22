#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<ll> A(N), C(N);
        for (int i = 0; i < N; i++) cin >> A[i];
        for (int i = 0; i < N; i++) cin >> C[i];

        vector<ll> vals = A;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        ll ans = 0;

        for (ll x : vals) {
            int greater = 0, ge = 0;
            vector<ll> cost;

            for (int i = 0; i < N; i++) {
                if (A[i] > x) greater++;
                if (A[i] >= x) ge++;
                else cost.push_back((x - A[i]) * C[i]);
            }

            if (greater > K) continue;

            int need = max(0, K + 1 - ge);
            if (need > (int)cost.size()) continue;

            sort(cost.begin(), cost.end());

            ll spend = 0;
            for (int i = 0; i < need; i++) spend += cost[i];

            ans = max(ans, 1LL * K * x - spend);
        }

        cout << ans << endl;
    }

    return 0;
}