// Author: S. Nithish Kumar :: nithish654 ::

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// POLICY-BASED DATA STRUCTURE - ORDERED_SET
template<class T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order - returns iterator, order_of_key, lower_bound, upper_bound - returns iterator
// .insert(x) .erase(x)

#define ll             long long
#define nl              cout << "\n";
#define endl            "\n"
#define vi              vector<ll>
#define yes             cout << "YES"
#define no              cout << "NO"
#define vpi             vector<pair<ll, ll>>
#define pb              push_back
#define ppb             pop_back
#define read(a)         for(auto &x : a) cin >> x;
#define u_m             unordered_map
#define pii             pair<ll, ll>
#define F               first
#define S               second
#define sqrt(x)         sqrtl(x)
#define INF             1e18
#define set_bits        __builtin_popcountll
#define M               1000000007
#define M1              1000000009
#define mod             998244353
#define sz(x)           (ll)(x).size()
#define all(x)          (x).begin(), (x).end()

#ifndef ONLINE_JUDGE
    #define print(x) cerr << #x <<" "; _print(x); cerr << ' ';
    #define println(x) cerr << #x <<" "; _print(x); cerr << "\n";
#else
    #define print(x)
    #define println(x)
#endif

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);

template <class T> void _print(T t){cerr << t;}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template<class T> void rev(T &v){reverse(v.begin(), v.end());}

ll power(ll a, ll b, ll m){ if(b == 0) return 1; ll ans = power(a, b/2, m); ans = (ans * ans)%m; if(b&1) return (ans * a)%m; return ans;}
ll inv(ll a, ll m){ a %= m; return power(a, m - 2, m);}
ll add(ll a, ll b, ll m){a %= m; b %= m; return (((a + b)%m) + m)%m;}
ll sub(ll a, ll b, ll m){a %= m; b %= m; return (((a - b)%m) + m)%m;}
ll mul(ll a, ll b, ll m){a %= m; b %= m; return (((a * b)%m) + m)%m;}
ll div(ll a, ll b, ll m){a %= m; b %= m; return (mul(a, inv(b, m), m) + m) %m;}
ll nCr(ll n, ll r, ll m, vector<ll>& fact){return mul(fact[n], inv(mul(fact[r], fact[n - r], m), m), m);}

struct custom_hash {static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31);} size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM);}};

const ll N = 2e5 + 10;

// http://xorshift.di.unimi.it/splitmix64.c

// Code Here        

bool test_cases = true;
void solution() {
    
}

int main() { 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);  
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
        freopen("error.txt", "w", stderr); 
    #endif 
    ll t = 1;if(test_cases) cin >> t; ll tc = 1;
    while(t--){
        //cout << "Test Case #" << tc << ":\n"; //kickstart 
        //cout << "Case " << tc << ": ";  //icpc
        tc++;
        solution(); nl;
    } 
    return 0; 
}
