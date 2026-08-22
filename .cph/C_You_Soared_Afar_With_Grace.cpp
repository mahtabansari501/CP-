/**
 * Author: Gemini
 * Problem: C. You Soared Afar With Grace
 */
#include <bits/stdc++.h>

using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<int> pos(n + 1); // Tracks position of value x in array a: pos[x] = index

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    // 1. Build position map
    for (int i = 0; i < n; i++) {
        pos[a[i]] = i;
    }

    // 2. Validation: Check pairs where a[i] == b[i]
    vector<int> self_pairs; // Indices where a[i] == b[i]
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            self_pairs.push_back(i);
        }
    }

    if (n % 2 == 0) {
        if (!self_pairs.empty()) {
            cout << -1 << endl;
            return;
        }
    } else {
        if (self_pairs.size() != 1) {
            cout << -1 << endl;
            return;
        }
    }

    vector<pair<int, int>> ans;

    // Helper lambda to swap two columns and update state
    auto swap_columns = [&](int i, int j) {
        if (i == j) return;
        
        // Update position map:
        // Value a[i] is moving to j, Value a[j] is moving to i
        pos[a[i]] = j;
        pos[a[j]] = i;

        // Perform physical swap
        swap(a[i], a[j]);
        swap(b[i], b[j]);
        
        // Record 1-based indices
        ans.push_back({i + 1, j + 1});
    };

    // 3. Handle Odd Middle Element
    if (n % 2 != 0) {
        int mid = n / 2;
        int current_idx = self_pairs[0];
        
        // The self-pair might have moved if we did pre-processing, 
        // but here we do it first, so pos is accurate.
        // Actually, let's use the pos map to be safe.
        // The value satisfying a[k] == b[k] is a[self_pairs[0]].
        int val = a[self_pairs[0]];
        current_idx = pos[val]; // Current position of the self-pair value

        if (current_idx != mid) {
            swap_columns(current_idx, mid);
        }
    }

    // 4. Greedy Matching for outer shells
    for (int i = 0; i < n / 2; i++) {
        int u = a[i];
        int v = b[i];

        // We need a pair (v, u) to be placed at j = n - 1 - i.
        // Look for the pair starting with 'v'.
        int target_idx = pos[v];

        // Validate that this column is actually (v, u)
        if (b[target_idx] != u) {
            cout << -1 << endl;
            return;
        }

        int j = n - 1 - i;
        if (target_idx != j) {
            swap_columns(target_idx, j);
        }
    }

    // Output result
    cout << ans.size() << endl;
    for (auto p : ans) {
        cout << p.first << " " << p.second << endl;
    }
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}