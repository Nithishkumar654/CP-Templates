#define ll              long long
#define sz(x)           (ll)(x).size()

ll power(ll a, ll b, ll m){ if(b == 0) return 1; ll ans = power(a, b/2, m); ans = (ans * ans)%m; if(b&1) return (ans * a)%m; return ans;}
ll inv(ll a, ll m){ a %= m; return power(a, m - 2, m);}
ll add(ll a, ll b, ll m){a %= m; b %= m; return (((a + b)%m) + m)%m;}
ll sub(ll a, ll b, ll m){a %= m; b %= m; return (((a - b)%m) + m)%m;}
ll mul(ll a, ll b, ll m){a %= m; b %= m; return (((a * b)%m) + m)%m;}
ll div(ll a, ll b, ll m){a %= m; b %= m; return (mul(a, inv(b, m), m) + m) %m;}
ll nCr(ll n, ll r, ll m, vector<ll>& fact){return mul(fact[n], inv(mul(fact[r], fact[n - r], m), m), m);}

class Hashing{
    ll n, base;
    string s;
    vector<ll> primes = {(ll)1e9 + 9, (ll)1e9 + 7};
    vector<vector<ll>> power, invPowers, prefix;
    public: 
    Hashing(string s){
        this->s = s;
        n = s.length();
        base = 31;
        power.resize(sz(primes));
        for(auto &v : power) v.resize(n + 1);
        prefix.resize(sz(primes));
        for(auto &v : prefix) v.resize(n + 1);
        invPowers.resize(sz(primes));
        for(auto &v : invPowers) v.resize(n + 1);

        build();
    }

    void build(){
        for(int i = 0; i < sz(primes); i++){
            power[i][0] = 1;
            for(int j = 1; j <= n; j++){
                power[i][j] = mul(power[i][j - 1], base, primes[i]);
            }
            invPowers[i][n] = inv(power[i][n], primes[i]);
            for(int j = n - 1; j >= 0; j--){
                invPowers[i][j] = mul(invPowers[i][j + 1], base, primes[i]);
            }
        }
        
        for(int i = 0; i < sz(primes); i++){
            for(int j = 0; j < n; j++){
                prefix[i][j] = add(j > 0 ? prefix[i][j - 1] : 0ll, mul(s[j] - 'a' + 1, power[i][j], primes[i]), primes[i]);
            }
        }
    }
    // l, r: 0-based indexing
    vector<ll> subStringHash(ll l, ll r){
        vector<ll> hash(sz(primes));
        for(int i = 0; i < sz(primes); i++){
            ll hl = l > 0 ? prefix[i][l - 1]: 0ll;
            ll hr = prefix[i][r];
            ll h = mul(sub(hr, hl, primes[i]), invPowers[i][l], primes[i]);
            hash[i] = h;
        }
        return hash;
    }

};
