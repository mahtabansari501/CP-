#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> cnt(30, 0);

        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;

            for (int b = 0; b < 30; b++) {
                if (x & (1 << b)) {
                    cnt[b]++;
                }
            }
        }

        bool ok = true;
        for (int b = 0; b < 30; b++) {
            if (cnt[b] > 1) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "Yes" : "No") << endl;
    }

    return 0;
}