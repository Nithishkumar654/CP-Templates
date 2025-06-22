//User function Template for C++
// https://www.geeksforgeeks.org/problems/articulation-point-1/1
class Solution {
  public:
    int dfs(vector<int> graph[], int node, int parent, int t, 
      vector<int>& tim, vector<int>& least, vector<bool>& vis, set<int>& ans){
      if(vis[node]) return tim[node];
      vis[node] = true;
      int children = 0;
      tim[node] = least[node] = t;
      for(auto child : graph[node]){
        if(child == parent) continue;
        if(vis[child] == false) children++;
        least[node] = min(least[node], dfs(graph, child, node, t + 1, tim, least, vis, ans));
      }
      if(parent > 0 && least[node] >= tim[parent]){
        ans.insert(parent);
      }
      if(children > 1 && parent == -1) {
        ans.insert(node);
      }
      return least[node];
    }
    
    vector<int> articulationPoints(int V, vector<int> graph[]) {
      vector<int> tim(V), least(V);
      set<int> ans;
      vector<bool> vis(V, false);
      for(int i = 0; i < V; i++){
        if(vis[i]) continue;
        dfs(graph, i, -1, 0, tim, least, vis, ans);
      }
      if(ans.size() == 0) return {-1};
      return vector<int>(ans.begin(), ans.end());
    }
};
