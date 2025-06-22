class DisjointSet {
  public:
  int n;
  vector<int> size, parent;

  DisjointSet(int n){
    this->n = n;
    size.resize(n + 1);
    parent.resize(n + 1);
    fill(size.begin(), size.end(), 1ll);
    iota(parent.begin(), parent.end(), 0ll);
  }

  int find(int u){
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
  }

  void merge(int u, int v){
    int pu = find(u), pv = find(v);
    if(pu == pv) return;
    if(size[pu] < size[pv]) swap(pu, pv);
    size[pu] += size[pv];
    parent[pv] = pu;
  }
};
using DSU = DisjointSet;
