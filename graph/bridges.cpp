template <typename T>
vector<bool> find_bridges(Undigraph<T> &g) {
  vector<bool> is_bridge(g.m, false);
  vector<bool> visited(g.n, false);
  vector<int> tin(g.n, -1);
  vector<int> low(g.n, -1); 
  int timer = 0;

  auto Dfs = [&](auto self, int node, int parent = -1) -> void {
    assert(!visited[node]);
    visited[node] = true;
    tin[node] = timer++;
    low[node] = tin[node];
    for (auto id : g.g[node]) {
      auto &e = g.edges[id];
      int to = node ^ e.from ^ e.to;
      bool parent_skipped = false;
      if (to == parent && !parent_skipped) {
        parent_skipped = true;
        continue;
      }
      if (visited[to]) {
        low[node] = min(low[node], tin[to]);
      } else {
        self(self, to, node);
        low[node] = min(low[node], low[to]);
        is_bridge[id] = (low[to] > tin[node]);
      }
    }
  };

  for (int node = 0; node < g.n; ++node) {
    if (!visited[node]) {
      Dfs(Dfs, node);
    }
  }

  // if graph has multiple edges, 
  // is_bridge is incorrectly true for some of them
  // we need to manually set is_bridge to false for all multiple edges
  map<pair<int, int>, int> mp;
  for (int id = 0; id < g.m; ++id) {
    auto &edge = g.edges[id];
    pair<int, int> e = {min(edge.from, edge.to), max(edge.from, edge.to)};
    if (mp.find(e) != mp.end()) {
      is_bridge[id] = false;
      is_bridge[mp[e]] = false;
    }
    mp[e] = id;
  }

  return is_bridge;
}