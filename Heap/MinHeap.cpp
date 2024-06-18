#define ll              long long
#define sz(x)           (ll)(x).size()
#define pb              push_back
#define ppb             pop_back

class MinHeap{
    public:
    vector<ll> minHeap;
    
    void insert(ll x){
        minHeap.pb(x);
        int i = sz(minHeap) - 1;
        while(i > 0){
            if(minHeap[i] < minHeap[(i - 1)/2]){
                swap(minHeap[i], minHeap[(i - 1)/2]);
            }
            i = (i - 1)/2;
        }
    }
    ll getMin(){
        return minHeap[0];
    }
    ll size(){
        return sz(minHeap);
    }
    void delMin(){
        int n = sz(minHeap);
        if(n == 0) return;
        swap(minHeap[0], minHeap[n - 1]);
        minHeap.ppb();
        int i = 0;
        n = sz(minHeap);
        while(true){
            int k = i;
            if(2*i+1 < n){
                if(minHeap[k] > minHeap[2*i+1]) k = 2*i+1;
            }
            if(2*i+2 < n){
                if(minHeap[k] > minHeap[2*i+2]) k = 2*i+2;
            }
            if(k == i) break;
            swap(minHeap[i], minHeap[k]);
            i = k;
        }
    }
};
