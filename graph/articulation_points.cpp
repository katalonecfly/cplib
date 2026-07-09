template <typename T>
vector<bool> find_articulation_points(Undigraph<T> &g) {
  vector<bool> is_articulation_point(g.n, false);
  vector<bool> visited(g.n, false);
  vector<int> tin(g.n, -1);
  vector<int> low(g.n, -1); 
  int timer = 0;

  auto Dfs = [&](auto self, int node, int parent = -1) -> void {
    assert(!visited[node]);
    visited[node] = true;
    tin[node] = timer++;
    low[node] = tin[node];
    int children = 0;
    for (auto id : g.g[node]) {
      auto &e = g.edges[id];
      int to = node ^ e.from ^ e.to;
      if (to == parent) continue;
      if (visited[to]) {
        low[node] = min(low[node], tin[to]);
      } else {
        self(self, to, node);
        low[node] = min(low[node], low[to]);
        if (low[to] >= tin[node] && parent != -1) {
          is_articulation_point[node] = true;
        }
        children++;
      }
    }
    if (parent == -1 && children > 1) {
      is_articulation_point[node] = true;
    }
  };

  for (int node = 0; node < g.n; ++node) {
    if (!visited[node]) {
      Dfs(Dfs, node);
    }
  }

  return is_articulation_point;
}