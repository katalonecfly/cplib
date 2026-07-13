class LcaRmq {
  public:
    int n;
    int timer;
    vector<vector<int>> adj;
    vector<int> euler;
    vector<int> first_occurrence;
    vector<bool> visited;
    vector<int> height;
    SparseTable<int, std::function<int(int,int)>> st;

    LcaRmq(const vector<vector<int>> &_adj, int root = 0) {
      adj = _adj;
      n = (int) adj.size();
      timer = 0;
      euler.reserve(2 * n);
      first_occurrence.resize(n);
      visited.assign(n, false);
      height.resize(n);
      
      dfs(root);

      st = SparseTable<int, std::function<int(int,int)>>(
        euler,
        [&](int u, int v) {
          return height[u] < height[v] ? u : v;
        }
      );
    }

    void dfs(int node, int h = 0) {
      visited[node] = true;
      height[node] = h;
      first_occurrence[node] = (int) euler.size();
      euler.push_back(node);
      for (auto to : adj[node]) {
        if (!visited[to]) {
          dfs(to, h + 1);
          euler.push_back(node);
        }
      }
    }

    int lca(int u, int v) {
      int l = first_occurrence[u];
      int r = first_occurrence[v];
      if (l > r) swap(l, r);
      return st.prod(l, r);
    }
};