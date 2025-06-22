
#define ll int64_t

void template(){
  vector<vector<pair<int, ll>>> graph(n + 1);
  vector<vector<int>> par(n + 1, vector<int>(31, 0));
  vector<ll> level(n + 1, 0), sum(n + 1, 0);
  
  for(auto &v : edges){
    v[0]++, v[1]++;
    graph[v[0]].push_back({v[1], v[2]});
    graph[v[1]].push_back({v[0], v[2]});
  }
  
  // par[i][j] = par[par[i][j - 1]][j - 1]
  auto dfs = [&](auto &dfs, int node, int parent, int l) -> void {
    level[node] = l;
    par[node][0] = parent;
    for(int i = 1; i <= 30; i++){
      par[node][i] = par[par[node][i - 1]][i - 1];
      if(par[node][i] == 0) break;
    }
    for(auto [child, w] : graph[node]){
      if(child == parent) continue;
      sum[child] = sum[node] + w;
      dfs(dfs, child, node, l + 1);
    }
  };
  
  
  dfs(dfs, 1, 0, 1);
  
  auto parent = [&](int node, int k) -> int {
    for(int i = 30; i >= 0; i--){
      if((k >> i) & 1){
          node = par[node][i];
          if(node == 0){
              break;
          }
      }
    }
    if(node == 0) return -1;
    return node;
  };
  
  auto LCA = [&](int x, int y) -> int {
    if(level[x] < level[y]) swap(x, y);
    int lx = level[x], ly = level[y];
    int d = lx - ly;
    // find dth parent of x
    x = parent(x, d);
    
    if(x == y) return x;
    
    // both are at same level
    for(int i = 30; i >= 0; i--){
      if(par[x][i] != par[y][i]){
          x = par[x][i], y = par[y][i];
      }
    }
    return par[x][0];
  };
}
