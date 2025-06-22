// https://leetcode.com/problems/critical-connections-in-a-network/
class Solution {
public:
  vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<int> time(n + 1), least(n + 1);
    vector<bool> vis(n + 1, false);
    vector<vector<int>> graph(n), ans;
    for(auto v : connections){
      graph[v[0]].push_back(v[1]);
      graph[v[1]].push_back(v[0]);
    }
    
    auto dfs = [&](auto && dfs, int node, int t, int parent) -> int {
      if(vis[node]) return time[node];
      vis[node] = true;
      time[node] = least[node] = t;
      for(auto child : graph[node]){
        if(child == parent) continue;
        least[node] = min(least[node], dfs(dfs, child, t + 1, node));
      }
      if(parent != -1 && least[node] > time[parent]) ans.push_back({node, parent});
      return least[node];
    };

    dfs(dfs, 0, 0, -1);
    return ans;
  }
};
