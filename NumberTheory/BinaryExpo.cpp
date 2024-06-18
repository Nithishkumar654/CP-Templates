#define ll    long long
#define M               1000000007

ll power(int a, int b){
    if(b == 0) return 1;
    ll ans = power(a, b/2);
    ans = (ans * ans)%M;
    if(b&1) return (ans * a)%M;
    return ans;
}
