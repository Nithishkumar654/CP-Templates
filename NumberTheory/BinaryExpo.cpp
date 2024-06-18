#define ll    long long
#define M               1000000007

ll power(ll a, ll b, ll mod){
    if(b == 0) return 1ll;
    ll ans = power(a, b/2, mod);
    ans = (ans * ans)%mod;
    if(b&1) return (ans * a)%mod;
    return ans;
}

ll inv(ll a, ll m){ a %= m; return power(a, m - 2, m);}
