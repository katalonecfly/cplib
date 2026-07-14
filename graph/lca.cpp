class Lca {
  public:
    int n;
    int l;
    int timer;
    vector<vector<int>> adj;
    vector<int> tin;
    vector<int> tout;
    vector<vector<int>> up;
    vector<int> depth;

    Lca(const vector<vector<int>> &_adj, int root = 0) {
      adj = _adj;
      n = (int) adj.size();
      l = ceil(log2(n));
      timer = 0;
      tin.resize(n);
      tout.resize(n);
      up.assign(n, vector<int>(l + 1, -1));
      depth.resize(n);
      dfs(root, -1, 0);
    }

    void dfs(int node, int parent, int d) {
      depth[node] = d;
      tin[node] = ++timer;
      up[node][0] = parent;
      for (int i = 1; i <= l; ++i) {
        if (up[node][i - 1] == -1) {
          up[node][i] = -1;
        } else {
          up[node][i] = up[up[node][i - 1]][i - 1];
        }
      }
      for (auto to : adj[node]) {
        if(to != parent) {
          dfs(to, node, d + 1);
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
        if(up[u][i] != -1 && !is_ancestor(up[u][i], v)) {
          u = up[u][i];
        }
      }
      return up[u][0];
    }

    int kth_ancestor (int v, int k) {
      if (k >> (l + 1)) {
        return -1;
      }
      for (int j = 0; j <= l && v != -1; ++j) {
        if (k & (1 << j)) {
          v = up[v][j];
        }
      }
      return v;
    }

    int distance (int u, int v) {
      return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }

    pair<int, pair<int, int>> diameter() {
      auto FarthestFrom = [&](int node) -> int{
        int best = -1;
        int best_dist = -1;
        for (int i = 0; i < n; ++i) {
          int dist = distance(node, i);
          if (dist > best_dist) {
            best_dist = dist;
            best = i;
          }
        }
        return best;
      };
      auto a = FarthestFrom(0);
      auto b = FarthestFrom(a);
      return {distance(a, b), {a, b}};
    }
};