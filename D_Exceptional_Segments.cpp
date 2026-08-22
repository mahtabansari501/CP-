#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        ll n, x;
        cin >> n >> x;

        ll ans;
        if (x % 2 == 1) {
            ans = (n - x) / 2 + 1;
        } else {
            ans = x / 2;
        }

        cout << ans % MOD << '\n';
    }
}