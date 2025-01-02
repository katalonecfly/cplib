template <typename T>
pair<int, vector<int>> strongly_connected_components_kosaraju(Digraph<T> &g) {
  vector<int> order;
  vector<bool> vis(g.n, false);
  auto dfs1 = [&](auto self, int v) -> void {
    vis[v] = true;
    for (int id : g.g[v]) {
      auto &e = g.edges[id];
      if (!vis[e.to]) {
        self(self, e.to);
      }
    }
    order.push_back(v);
  };

  for (int v = 0; v < g.n; ++v) {
    if (!vis[v]) {
      dfs1(dfs1, v);
    }
  }

  Digraph<T> g_rev = reverse_graph(g);
  vector<int> comp(g.n, -1);
  auto dfs2 = [&](auto self, int v) -> void {
    for (int id : g_rev.g[v]) {
      auto &e = g_rev.edges[id];
      if (comp[e.to] == -1) {
        comp[e.to] = comp[v];
        self(self, e.to);
      }
    }
  };

  int C = 0;
  for (int i = g.n - 1; i >= 0; --i) {
    int v = order[i];
    if (comp[v] != -1) continue;
    comp[v] = C++;
    dfs2(dfs2, v);
  }
  return {C, comp};
}