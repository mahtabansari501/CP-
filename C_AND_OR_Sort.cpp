#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        if (s[0] == '1') {
            int ans = 0;

            for (char c : s) {
                if (c == '0') ans++;
            }

            cout << ans << endl;
            continue;
        }

        // Initially boundary is after index 0:
        // 0 | s[1...n-1]
        int ones = 0;
        int zeros = 0;

        for (int i = 1; i < n; i++) {
            if (s[i] == '0') zeros++;
        }

        int ans = zeros;

        // Move boundary
        for (int i = 1; i < n; i++) {
            if (s[i] == '1') {
                ones++;
            } else {
                zeros--;
            }

            ans = min(ans, ones + zeros);
        }

        cout << ans << endl;
    }

    return 0;
}