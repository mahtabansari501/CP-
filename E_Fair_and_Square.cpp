#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> a(n + 1);
        vector<int> good(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            int r = (int)sqrt((long double)a[i]);
            good[i] = (1LL * r * r == a[i]);
        }

        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> parent(n + 1), sub(n + 1);

        function<void(int,int)> dfs = [&](int u, int p) {
            parent[u] = p;
            sub[u] = 1;
            for (int v : adj[u]) {
                if (v == p) continue;
                dfs(v, u);
                sub[u] += sub[v];
            }
        };

        dfs(1, 0);

        ll squarewf = 0;

        for (int u = 1; u <= n; u++) {
            if (!good[u]) continue;

            vector<ll> comp;
            ll sum = 0;

            if (parent[u]) {
                ll x = n - sub[u];
                comp.push_back(x);
                sum += x;
            }

            for (int v : adj[u]) {
                if (v == parent[u]) continue;
                ll x = sub[v];
                comp.push_back(x);
                sum += x;
            }

            ll pairSum = 0;
            ll pref = 0;
            ll prefPair = 0;
            ll tripleSum = 0;

            for (ll s : comp) {
                pairSum += pref * s;
                tripleSum += prefPair * s;
                prefPair += pref * s;
                pref += s;
            }

            squarewf += pairSum;
            squarewf += tripleSum;
        }

        cout << squarewf << endl;
    }

    return 0;
}