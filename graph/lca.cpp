class Lca {
  public:
    int n;
    int l;
    int timer;
    vector<vector<int>> adj;
    vector<int> tin;
    vector<int> tout;
    vector<vector<int>> up;

    Lca(const vector<vector<int>> &_adj, int root = 0) {
      adj = _adj;
      n = (int) adj.size();
      l = ceil(log2(n));
      timer = 0;
      tin.resize(n);
      tout.resize(n);
      up.assign(n, vector<int>(l + 1));
      dfs(root, root);
    }

    void dfs(int node, int parent) {
      tin[node] = ++timer;
      up[node][0] = parent;
      for (int i = 1; i <= l; ++i) {
        up[node][i] = up[up[node][i - 1]][i - 1];
      }
      for (auto to : adj[node]) {
        if(to != parent) {
          dfs(to, node);
        }
      }
      tout[node] = ++timer;
    }

    bool is_ancestor(int u, int v) {
      return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int lca(int u, int v) {
      if (is_ancestor(u, v)) {
        return u;
      }
      if (is_ancestor(v, u)) {
        return v;
      }
      for (int i = l; i >= 0; --i) {
        if(!is_ancestor(up[u][i], v)) {
          u = up[u][i];
        }
      }
      return up[u][0];
    }
};