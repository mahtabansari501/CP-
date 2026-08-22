/* Author: manoJaat_3003 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define f(i,a,b) for(ll i=a;i<b;i++)
#define endl '\n'

const ll INF = 2e9;

// ================= CHECK FUNCTION =================
bool f2(ll mid, ll s, vector<ll> &a, ll n){
    ll sum = 0;
    f(i,0,n){
        if(a[i] > mid){
            sum += (a[i] - mid);
            if(sum > s) return false; // early stop (optimization)
        }
    }
    return sum <= s;
}

// ================= SOLVE =================
void solve(){
    ll n, s;
    cin >> n >> s;

    vector<ll> a(n);
    f(i,0,n) cin >> a[i];

    // Initial answer for original array
    ll lo = 0, hi = INF;

    while(hi - lo > 1){
        ll mid = (lo + hi) / 2;
        if(f2(mid, s, a, n)) hi = mid;
        else lo = mid + 1;
    }

    ll x;
    if(f2(lo, s, a, n)) x = lo;
    else x = hi;

    ll q;
    cin >> q;

    while(q--){
        ll idx, v;
        cin >> idx >> v;
        idx--;  // 0-based indexing

        ll old = a[idx];
        a[idx] = v;   // update element

        // Recompute answer using binary search
        ll lo = 0, hi = INF;

        while(hi - lo > 1){
            ll mid = (lo + hi) / 2;
            if(f2(mid, s, a, n)) hi = mid;
            else lo = mid + 1;
        }

        ll ans;
        if(f2(lo, s, a, n)) ans = lo;
        else ans = hi;

        cout << ans << endl;

        a[idx] = old;  // restore original value (if queries independent)
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}