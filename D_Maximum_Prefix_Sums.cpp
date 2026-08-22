/* Author: mahtabansari911*/
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#include <chrono>

using namespace std;
// using namespace __gnu_pbds;
using namespace chrono;

// =================================== بِسْمِ ٱللّٰهِ ٱلرَّحْمَـٰنِ ٱلرَّحِيمِ ===================================
// ==========================================================================

// --- Type Aliases & Your Macros ---

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vs = vector<string>;
using vb = vector<bool>;
using pll = pair<ll, ll>;
using vp = vector<pair<ll, ll>>;

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define ff first
#define ss second
#define endl '\n'

// --- Looping Macros ---
#define f(i, a, b) for (ll i = a; i < b; i++)
#define fr(i, a, b) for (ll i = a - 1; i >= b; i--)
#define fa(v) for (auto &it : (v))

// --- Output Macros ---
#define yes cout << "Yes" << endl
#define no cout << "No" << endl

// --- Policy-Based Data Structure (PBDS) ---
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// --- Fast I/O ---
void fastio() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

// // --- Debugging ---
// #ifndef ONLINE_JUDGE
// #define dbg(...) cerr << #_VA_ARGS_ << " : "; print(VA_ARGS_);
// void _print(ll t) {cerr << t << endl;}
// void _print(string t) {cerr << t << endl;}
// void _print(char t) {cerr << t << endl;}
// template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}" << endl;}
// template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]" << endl;}
// #else
// #define dbg(...)
// #endif

// --- Constants ---
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const double PI = 3.141592653589793238462;

// --- Bit Manipulation Cheatsheet ---
// __builtin_popcountll(n)       // Counts set bits (1s). Ex: 13 (1101) -> 3
// __builtin_parityll(n)       // Parity of set bits (1=odd, 0=even). Ex: 13 -> 1
// __builtin_clzll(n)          // Counts leading zeros. Undefined for n=0.
// __builtin_ctzll(n)          // Counts trailing zeros. Undefined for n=0.
// __builtin_ffsll(n)          // 1-indexed LSB. Returns 0 if n=0. Ex: 12 (1100) -> 3
// Classic Hacks:
// Check i-th bit: (n & (1LL << i)) != 0
// Set i-th bit:   n |= (1LL << i)
// Clear i-th bit: n &= ~(1LL << i)
// Get LSB value:  n & -n
// Clear LSB:      n &= (n - 1)

// ==========================================================================
// =================== FUNCTIONS & DATA STRUCTURES ==========================
// ==========================================================================

// --- Math Functions ---
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll power(ll base, ll exp, ll mod = MOD) {
    ll res = 1; base %= mod;
    while (exp > 0) { if (exp % 2 == 1) res = (res * base) % mod; base = (base * base) % mod; exp /= 2; }
    return res;
}
ll modInverse(ll n, ll mod = MOD) { return power(n, mod - 2, mod); }

// --- Modular Arithmetic ---
ll mod_add(ll a, ll b, ll m = MOD) { a = a % m; b = b % m; return (((a + b) % m) + m) % m; }
ll mod_mul(ll a, ll b, ll m = MOD) { a = a % m; b = b % m; return (((a * b) % m) + m) % m; }
ll mod_sub(ll a, ll b, ll m = MOD) { a = a % m; b = b % m; return (((a - b) % m) + m) % m; }
ll mod_div(ll a, ll b, ll m = MOD) { a = a % m; b = b % m; return (mod_mul(a, modInverse(b, m), m)); }

// --- Combinatorics ---
vll fact;
void precompute_factorials(int n) {
    fact.resize(n + 1); fact[0] = 1;
    f(i, 1, n + 1) fact[i] = mod_mul(fact[i - 1], i);
}
ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return mod_div(fact[n], mod_mul(fact[r], fact[n - r]));
}

// --- Disjoint Set Union (DSU) ---
vll parent, set_size;

void dsu_make(int n) {
    parent.resize(n + 1);
    iota(all(parent), 0);
    set_size.assign(n + 1, 1);
}

ll find_set(ll i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find_set(parent[i]);
}

void unite_sets(ll i, ll j) {
    ll root_i = find_set(i);
    ll root_j = find_set(j);
    if (root_i != root_j) {
        if (set_size[root_i] < set_size[root_j])
            swap(root_i, root_j);
        parent[root_j] = root_i;
        set_size[root_i] += set_size[root_j];
    }
}
// --- Sieve of Eratosthenes ---
vector<bool> sieve(ll n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (ll j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    return isPrime;
}
 
// --- Simple primality check ---
bool isPrimeSimple(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}
bool checkbinary(vector<ll>&a,ll k,ll mid){

}


// ==========================================================================
// ============================  SOLVE  =====================================
// ==========================================================================

void solve() {
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vector<ll>a(n),c(n),b(n);
    f(i,0,n){
        cin>>a[i];
    }
    f(i,0,n){
        cin>>c[i];
    }
    ll cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            if(i==0){
                a[i]=c[i];
            }
            else if(i==n-1){
                if(c[i]==c[i-1]){
                    a[i]=0;
                }
                else{
                    a[i]=c[i]-cnt;
                }
            }
            else{
                if(c[i]==c[i-1]){
                    if(s[i+1]=='0'){
                        a[i]=0;
                    }
                    else{
                       ll sum2=0;
                       ll j=i+1;
                       ll y = c[i]-cnt; 
                       while(j<n&&s[j]!='0'){
                            sum2+=a[j];
                            y=min(y,c[j]-cnt-sum2); 
                            j++;
                        }
                        a[i]=y;
                    }       
                }
                else{
                    a[i]=c[i]-cnt;
                }
            }
        }
        cnt+=a[i];
    }
    /*for(auto it:a){
        cout<<it<<" ";
    }*/
    ll sum=0;
    ll maxi=a[0];
    for(int i=0;i<n;i++){
        sum+=a[i];
        maxi=max(maxi,sum);
        if(maxi!=c[i]){
            cout<<"No"<<endl;
            return;
        }
        
    }
    cout<<"Yes"<<endl;
    for(auto it:a){
        cout<<it<<" ";
    }
    cout<<endl;

}

// ==========================================================================
// ============================  MAIN  ======================================
// ==========================================================================

int main() {
    fastio();
    //ll t=1;
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}