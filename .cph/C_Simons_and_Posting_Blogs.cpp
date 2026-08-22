#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> blogs(n);

        for (int i = 0; i < n; i++) {
            int l;
            cin >> l;
            blogs[i].resize(l);

            for (int j = 0; j < l; j++) {
                cin >> blogs[i][j];
            }
        }

        unordered_set<int> used;
        vector<int> ans;

        // reverse blogs
        for (int i = n - 1; i >= 0; i--) {
            // reverse inside blog
            for (int j = blogs[i].size() - 1; j >= 0; j--) {
                int x = blogs[i][j];

                if (used.find(x) == used.end()) {
                    used.insert(x);
                    ans.push_back(x);
                }
            }
        }

        // reverse final answer
        reverse(ans.begin(), ans.end());

        for (auto x : ans) cout << x << " ";
        cout << endl;
    }

    return 0;
}