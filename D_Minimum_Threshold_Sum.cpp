#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll S;
    cin >> n >> S;

    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    vector<ll> sorted = a;
    sort(sorted.begin(), sorted.end());

    vector<ll> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + sorted[i];
    }

    auto get_sum = [&](ll T) {
        int pos = upper_bound(sorted.begin(), sorted.end(), T) - sorted.begin();
        ll cnt = n - pos;
        ll sum = pref[n] - pref[pos];
        return sum - cnt * T;
    };

    int q;
    cin >> q;

    while (q--) {
        int i;
        ll v;
        cin >> i >> v;
        i--;

        ll old = a[i];

        ll lo = 0, hi = 1e9, ans = hi;

        while (lo <= hi) {
            ll mid = (lo + hi) / 2;

            ll cur = get_sum(mid);

            // remove old contribution
            if (old > mid) cur -= (old - mid);

            // add new contribution
            if (v > mid) cur += (v - mid);

            if (cur <= S) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        cout << ans << '\n';
    }
}