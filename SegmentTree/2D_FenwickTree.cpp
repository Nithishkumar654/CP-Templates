#define ll int64_t

class FenwickTree2D {
  public:
  vector<vector<ll>> tree;  // binary indexed tree
  int n;
 
  FenwickTree2D(int n) {
    this->n = n;
    tree.resize(n);
    for(auto &x : tree)
      x.assign(n, 0);
  }

  // returns value corresponding to submatrix (0, 0) to (x, y)
  ll sum(int x, int y) {
    ll ret = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
      for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
        ret += tree[i][j];
    return ret;
  }

  // point increment (0-based indexing)
  void add(int x, int y, ll delta) {
    for (int i = x; i < n; i = i | (i + 1))
      for (int j = y; j < n; j = j | (j + 1))
        tree[i][j] += delta;
  }
}
