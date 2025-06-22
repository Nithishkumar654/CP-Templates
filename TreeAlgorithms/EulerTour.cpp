
// Flattening a tree
vector<int> EulerTour() {
  vector<int> flatten, start(n + 1, 0), end(n + 1, 0);
  flatten.push_back(0);
  // Flatten the tree
  auto dfs = [&](auto &dfs, int node, int parent) -> void {
    start[node] = flatten.size();
    flatten.push_back(v[node]);
    for(int child : graph[node]){
      if(child == parent) continue;
      dfs(dfs, child, node);
    }
    end[node] = flatten.size();
    flatten.push_back(v[node]);
  };
  
  dfs(dfs, 1, 0);

  return flatten;
}
