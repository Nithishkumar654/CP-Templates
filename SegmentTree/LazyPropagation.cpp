#define ll int64_t
class SegmentTree{
  vector<ll> segTree, lazy;
  int n;
  
  void push(int i, int l, int h){
    if(lazy[i] == -1) return;
    
    segTree[i] = lazy[i];
    if(l != h){
      lazy[2*i + 1] = lazy[i];
      lazy[2*i + 2] = lazy[i];
    }
    
    lazy[i] = -1;
  }
 
  ll combine(ll a, ll b){
    return a + b;
  }
  
  void update(int i, int low, int high, ll val, int l, int r){
    
    push(i, low, high);
    
    if(low > r or high < l) return;
 
    if(low >= l and high <= r){
      lazy[i] = val;
      push(i, low, high);
      return;
    }
    
    int mid = (low + high) >> 1;
    update(2*i + 1, low, mid, val, l, r);
    update(2*i + 2, mid+1, high, val, l, r);
    segTree[i] = combine(segTree[2*i + 1], segTree[2*i + 2]);
  }
 
  ll query(int i, int low, int high, int l, int r){
    
    push(i, low, high);
 
    if(low > r or high < l) return 0ll;
    if(low >= l and high <= r) return segTree[i];
 
    int mid = (low + high) >> 1;
    ll left = query(2*i + 1, low, mid, l, r);
    ll right = query(2*i + 2, mid + 1, high, l, r);
    
    return combine(left, right);  
  }
 
 
  public:
  SegmentTree(int n){
    this->n = n;
    segTree.resize(4*n + 1);
    lazy.resize(4*n + 1);
    fill(segTree.begin(), segTree.end(), 0);
    fill(lazy.begin(), lazy.end(), -1);
  }
 
  void update(int l, int r, ll val){
    update(0, 0, n - 1, val, l, r);
  }
 
  ll query(int l, int r){
    return query(0, 0, n - 1, l, r);
  }
};
