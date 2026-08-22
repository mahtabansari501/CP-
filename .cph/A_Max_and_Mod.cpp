/* Author: manoJaat_3003 */
#include <bits/stdc++.h>

// --- PBDS (Commented out for compatibility) ---
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
// using namespace __gnu_pbds;

// =================================== ॐ ===================================

// --- Type Aliases ---
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vs = vector<string>;
using vb = vector<bool>;
using pll = pair<ll, ll>;
using vp = vector<pair<ll, ll>>;
// template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// --- Macros ---
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(x) (ll)(x).size()
#define pb push_back
#define ff first
#define ss second
#define endl '\n'

// --- Loop Macros ---
#define f(i, a, b) for (ll i = a; i < b; i++)
#define fr(i, a, b) for (ll i = a - 1; i >= b; i--)
#define fa(v) for (auto &it : (v))

// --- Output Macros ---
#define yes cout << "Yes" << endl
#define no cout << "No" << endl

// --- Constants ---
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const double PI = 3.141592653589793238462;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

// --- Fast I/O ---
void fastio() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

// --- Input / Output Overloads ---
template<typename T1, typename T2> istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> istream& operator>>(istream &istream, vector<T> &p) { for (auto &x : p) istream >> x; return istream; }
template<typename T1, typename T2> ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &x : c) ostream << x << " "; return ostream; }

// --- Debugging ---
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
void _print() { cerr << "]" << endl; }
template <typename T, typename... V> void _print(T t, V... v) { _print(t); if (sizeof...(v)) cerr << ", "; _print(v...); }
void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << '"' << t << '"'; }
void _print(char t) { cerr << '\'' << t << '\''; }
void _print(ld t) { cerr << t; }
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}"; }
template <class T> void _print(vector <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]"; }
template <class T> void _print(set <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]"; }
template <class T> void _print(multiset <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]"; }
template <class T, class V> void _print(map <T, V> v) { cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]"; }
#else
#define debug(x...)
#endif

// --- Custom Hash (Anti-Hack) ---
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); }
    size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM); }
};
template <typename K, typename V> using safe_map = unordered_map<K, V, custom_hash>;

// =================== CORE FUNCTIONS ===================

// --- Bit Manipulation Cheatsheet ---
// __builtin_popcountll(n)      // Counts set bits (1s).
// __builtin_parityll(n)        // Parity of set bits (1=odd, 0=even).
// __builtin_clzll(n)           // Counts leading zeros.
// __builtin_ctzll(n)           // Counts trailing zeros.
// __builtin_ffsll(n)           // 1-indexed LSB.
// Check i-th bit: (n & (1LL << i)) != 0
// Set i-th bit:   n |= (1LL << i)
// Clear i-th bit: n &= ~(1LL << i)

// --- Math & Modular Arithmetic ---
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll ceil_div(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); }
ll floor_div(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }
ll madd(ll a, ll b) { return (a + b) % MOD; }
ll msub(ll a, ll b) { return (((a - b) % MOD) + MOD) % MOD; }
ll mmul(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }
ll power(ll base, ll exp) {
    ll res = 1; base %= MOD;
    while (exp > 0) { if (exp % 2 == 1) res = (res * base) % MOD; base = (base * base) % MOD; exp /= 2; }
    return res;
}
ll modInverse(ll n) { return power(n, MOD - 2); }
ll mdiv(ll a, ll b) { return mmul(a, modInverse(b)); }

// --- Combinatorics (nCr) ---
vll fact, invFact;
void init_fact(int n) {
    fact.resize(n + 1); invFact.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = mmul(fact[i - 1], i);
    invFact[n] = modInverse(fact[n]);
    for (int i = n - 1; i >= 0; i--) invFact[i] = mmul(invFact[i + 1], i + 1);
}
ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return mmul(fact[n], mmul(invFact[r], invFact[n - r]));
}

// --- Prime Sieve & Factors (SPF) ---
vll spf; 
void sieve(int n) {
    spf.resize(n + 1); iota(all(spf), 0);
    for (int i = 2; i * i <= n; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= n; j += i)
                if (spf[j] == j) spf[j] = i;
        }
    }
}
map<ll, int> getFactors(int n) {
    map<ll, int> factors;
    while (n > 1) { factors[spf[n]]++; n /= spf[n]; }
    return factors;
}

// --- DSU (Union Find) ---
struct DSU {
    vll parent, size;
    DSU(int n) {
        parent.resize(n + 1); iota(all(parent), 0);
        size.assign(n + 1, 1);
    }
    ll find(ll i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    void unite(ll i, ll j) {
        ll root_i = find(i), root_j = find(j);
        if (root_i != root_j) {
            if (size[root_i] < size[root_j]) swap(root_i, root_j);
            parent[root_j] = root_i;
            size[root_i] += size[root_j];
        }
    }
};

// ==========================================================================
// ============================  SOLVE  =====================================
// ==========================================================================

void solve() {
    ll n;cin>>n;
    if(n%2==0){
        cout<<-1<<endl;
        return;

    }
    else{
        cout<<n<<" "<<2<<" "<<1<<" ";
        f(i,3,n){
            cout<<i<<" ";
        }cout<<endl;
    }
}

int main() {
    fastio();
    // init_fact(200005); // Uncomment for nCr
    // sieve(200005);     // Uncomment for Primes
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}