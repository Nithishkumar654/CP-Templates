#define ll    long long
#define M               1000000007

ll power(ll a, ll b){
    if(b == 0) return 1ll;
    ll ans = power(a, b/2);
    ans = (ans * ans)%M;
    if(b&1) return (ans * a)%M;
    return ans;
}

ll inv(ll a, ll m){ a %= m; return power(a, m - 2, m);}
