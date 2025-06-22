#define ll int64_t
class SegmentTree {
  vector<ll> segTree;
  int n;
 
  ll combine(ll a, ll b) {
    return max(a, b);
  }
 
  void update(int i, int l, int h, ll val, int idx) {
    if (l == h) {
      segTree[i] = val; // replacing  by val
      return;
    }
    int mid = (l + h) / 2;
    if (idx <= mid) update(2 * i + 1, l, mid, val, idx);
    else update(2 * i + 2, mid + 1, h, val, idx);
    segTree[i] = combine(segTree[2 * i + 1], segTree[2 * i + 2]);
  }
 
  ll query(int i, int low, int high, int l, int r) {
    if (low >= l && high <= r) return segTree[i];
    if (low > r || high < l) return -INF;
    int mid = (low + high) / 2;
    ll left = query(2 * i + 1, low, mid, l, r);
    ll right = query(2 * i + 2, mid + 1, high, l, r);
    return combine(left, right);
  }
 
public:
  SegmentTree(int n) {
    this->n = n;
    segTree.resize(4 * n);
    fill(segTree.begin(), segTree.end(), -INF);
  }
 
  void update(int idx, ll val) {
    update(0, 0, n - 1, val, idx);
  }
 
  ll query(int l, int r) {
    return query(0, 0, n - 1, l, r);
  }
};
