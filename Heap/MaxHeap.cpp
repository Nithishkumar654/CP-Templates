#define ll              long long
#define sz(x)           (ll)(x).size()
#define pb              push_back
#define ppb             pop_back

class MaxHeap{
    public:
    vector<ll> maxHeap;
    
    void insert(ll x){
        maxHeap.pb(x);
        int i = sz(maxHeap) - 1;
        while(i > 0){
            if(maxHeap[i] > maxHeap[(i - 1)/2]){
                swap(maxHeap[i], maxHeap[(i - 1)/2]);
            }
            i = (i - 1)/2;
        }
    }
    ll getMax(){
        return maxHeap[0];
    }
    ll size(){
        return sz(maxHeap);
    }
    void delMax(){
        int n = sz(maxHeap);
        if(n == 0) return;
        swap(maxHeap[0], maxHeap[n - 1]);
        maxHeap.ppb();
        int i = 0;
        n = sz(maxHeap);
        while(true){
            int k = i;
            if(2*i+1 < n){
                if(maxHeap[k] < maxHeap[2*i+1]) k = 2*i+1;
            }
            if(2*i+2 < n){
                if(maxHeap[k] < maxHeap[2*i+2]) k = 2*i+2;
            }
            if(k == i) break;
            swap(maxHeap[i], maxHeap[k]);
            i = k;
        }
    }
};
