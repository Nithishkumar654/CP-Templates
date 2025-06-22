// https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
class Solution{
	void dfs(int node, vector<vector<int>>& graph, vector<bool>& vis){
    if(vis[node]) return;
    vis[node] = true;
    for(int child : graph[node]){
      dfs(child, graph, vis);
    }
	}
	
	void dfs(int node, vector<vector<int>>& graph, vector<bool>& vis, stack<int>& st){
   if(vis[node]) return;
    vis[node] = true;
    for(int child : graph[node]){
      dfs(child, graph, vis, st);
    }
    st.push(node);
	}
	
	public:
	//Function to find number of strongly connected components in the graph.
  int kosaraju(int V, vector<vector<int>>& adj){
    stack<int> st;
    vector<bool> vis(V, false);
    for(int i = 0; i < V; i++){
      if(vis[i]) continue;
      dfs(i, adj, vis, st);
    }
    
    vector<vector<int>> graph(V);
    for(int i = 0; i < V; i++){
      vis[i] = false;
      for(int x : adj[i]){
        graph[x].push_back(i);
      }
    }
    int ans = 0;
    while(!st.empty()){
      int node = st.top();
      st.pop();
      if(vis[node]) continue;
      dfs(node, graph, vis);
      ans++;
    }
    return ans;
  }
};
