/* HEAVY LIGHT DECOMPOSITION */
 
int n;
int tree[4 * N];
 
int combine(int a, int b){
  return max(a, b);
}
 
void update(int pos, int val){
  for(tree[pos += n] = val; pos > 1; pos >>= 1) 
      tree[pos >> 1] = combine(tree[pos], tree[pos ^ 1]);
}
 
int max_query(int l, int r){
  int res = 0;
  for(l += n, r += n; l < r; l >>= 1, r >>= 1){
    if(l & 1) res = combine(res, tree[l++]);
    if(r & 1) res = combine(res, tree[--r]);
  }
  return res;
}
 
 
int subtree_size[N], head[N], val[N], par[N];
int heavy_child[N], pos[N], depth[N];
vector<int> graph[N];
int cur_pos = 0;
 
void dfs(int node, int parent){
  int mx = 0;
  for(int child : graph[node]){
    if(child == parent) continue;

    par[child] = node;
    depth[child] = depth[node] + 1;
    
    dfs(child, node);
    
    subtree_size[node] += subtree_size[child];
    if(mx < subtree_size[child]){
      mx = subtree_size[child];
      heavy_child[node] = child;
    }
  }
}
 
void dfs_decompose(int node, int parent, int h){
 
  pos[node] = cur_pos++;
  head[node] = h;
  
  update(pos[node], val[node]);
  if(heavy_child[node] != -1){
    dfs_decompose(heavy_child[node], node, head[node]);
  }

  for(int child : graph[node]){
    if(child == parent or heavy_child[node] == child) continue;
    dfs_decompose(child, node, child);
  }
}
 
 
int query(int a, int b){
  int res = 0;
  while(head[a] != head[b]){
    if(depth[head[a]] > depth[head[b]]) 
        swap(a, b);
    int cur_heavy_path_max = max_query(pos[head[b]], pos[b] + 1);
    res = combine(res, cur_heavy_path_max);
    b = par[head[b]];
  }
  if(depth[a] > depth[b])
    swap(a, b);

  int last_heavy_path_max = max_query(pos[a], pos[b] + 1);
  res = combine(res, last_heavy_path_max);
  return res;
}
