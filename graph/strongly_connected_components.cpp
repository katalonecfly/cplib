template <typename T>
pair<int, vector<int>> strongly_connected_components(Digraph<T> &g) {
  int C = 0;
  vector<int> low(g.n), ord(g.n, -1), comp(g.n);
  vector<int> stk;
  stk.reserve(g.n);
  int cur = 0;
  auto dfs = [&](auto self, int v) -> void {
    low[v] = cur;
    ord[v] = cur;
    cur++;
    stk.push_back(v);
    for (int id : g.g[v]) {
      auto &e = g.edges[id];
      if (ord[e.to] == -1) {
        self(self, e.to);
        low[v] = min(low[v], low[e.to]);
      } else {
        low[v] = min(low[v], ord[e.to]);
      }
    }
    if (low[v] == ord[v]) {
      int u;
      do {
        u = stk.back();
        stk.pop_back();
        ord[u] = g.n;
        comp[u] = C;
      } while(v != u);
      ++C;
    }
  };
  for (int v = 0; v < g.n; ++v) {
    if (ord[v] == -1) {
      dfs(dfs, v);
    }
  }
  for (int v = 0; v < g.n; ++v) {
    comp[v] = C - 1 - comp[v];
  }
  return {C, comp};
}