#define ll      long long

const int N = 2e5 + 10;
vector<bool> prime(N + 1, true);
vector<ll> smallestPrime(N, -1);

void sieve(){
    prime[0] = prime[1] = false;
    for(int i = 2; i * i <= N; i++){
        if(prime[i] == true){
            smallestPrime[i] = i;
            for(int j = i * i; j <= N; j += i){
                prime[j] = false;
                if(smallestPrime[j] == -1) smallestPrime[j] = i;
            }
        }
    }
}
