#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vs vector<string>
#define vp vector<pair<ll,ll>>
#define vb vector<bool>
#define endl '\n'
#define f(i,a,b) for( ll i=a;i<b;i++)
#define fr(i,a,b) for( ll i=a-1;i>=b;i--)
#define fa(v) for(auto &it : (v))
#define all(a) (a).begin(),(a).end()
#define ff first
#define ss second

// --- Bit Manipulation Cheatsheet ---
// Assumes: using namespace std;

// -- GCC/Clang Built-ins (ll suffix for long long) --
// __builtin_popcountll(n)      // Counts set bits (1s). Ex: 13 (1101) -> 3
// __builtin_parityll(n)        // Parity of set bits (1=odd, 0=even). Ex: 13 -> 1
// __builtin_clzll(n)           // Counts leading zeros. Undefined for n=0. (MSB index: 63 - clzll(n))
// __builtin_ctzll(n)           // Counts trailing zeros. Undefined for n=0. (LSB index: ctzll(n))
// __builtin_ffsll(n)           // 1-indexed LSB. Returns 0 if n=0. Ex: 12 (1100) -> 3

// -- C++20 Standard Library <bit> --
// #include <bit>
// popcount(n)             // Counts set bits (1s).
// has_single_bit(n)       // Checks if n is a power of 2.
// countl_zero(n)          // Counts leading zeros (safe for n=0).
// countr_zero(n)          // Counts trailing zeros (safe for n=0).
// rotl(n, s), rotr(n, s)  // Bitwise rotate left/right.
// byteswap(n)             // Reverses byte order (C++23).

// -- Classic Bit Hacks --
// Check i-th bit:   (n & (1LL << i)) != 0
// Set i-th bit:     n |= (1LL << i)
// Clear i-th bit:   n &= ~(1LL << i)
// Toggle i-th bit:  n ^= (1LL << i)
// Get LSB value:    n & -n
// Clear LSB:        n &= (n - 1)
// Is power of two:  (n > 0) && ((n & (n - 1)) == 0)

// =================================== = =================================== 
// ==========================================================================


void solve(){
    int n;
        cin>>n;
        string s;
        cin>>s;
        if(n&1){
            cout<<-1<<endl;
        }
        else{
            int l=0,r=n-1;
            int cnt=0;
            vector<int>a(0);
            while(l<r&&cnt<300){
                if(s[l]==s[r]){
                    if(s[l]=='0'){
                    cnt++;
                    a.push_back(r+1);
                    s.insert(r+1,"01");
                    r=s.size()-1;
                    l=0;
                    }
                    else{
                        cnt++;
                        a.push_back(l);
                        s.insert(l,"01");
                        r=s.size()-1;
                        l=0;
                    }
                }
                else{
                    l++;
                    r--;
                }
            }
            if(cnt<300){
                cout<<a.size()<<endl;
                for(int i=0;i<a.size();i++){
                   cout<<a[i]<<" ";
                }
                cout<<endl;
            }
            else{
                cout<<-1<<endl;
            }
        }

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}