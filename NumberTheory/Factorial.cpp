#define M  1000000007
#define ll long long
const int N = 2e5 + 10;

vector<ll> fact(N, 1);

void factorial(){
    fact[0] = fact[1] = 1;
    for(int i = 2; i < N; i++){
        fact[i] = i*1ll*fact[i - 1];
        fact[i] %= M;
    }
}
