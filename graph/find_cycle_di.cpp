template <typename T>
pair<vector<int>, vector<int>> find_cycle_di (Digraph<T> &g) {
  vector<int> parent(g.n, -1);
  vector<int> parent_edge(g.n, -1);
  vector<int> color(g.n, 0);
  int fi_node = -1;
  int la_node = -1;

  auto dfs = [&](auto self, int v) -> bool {
    color[v] = 1;
    for (auto id : g.g[v]) {
      auto &e = g.edges[id];
      int to = v ^ e.from ^ e.to;
      parent_edge[to] = id;
      if (color[to] == 0) {
        parent[to] = v;
        if (self(self, to)) return true;
      } else if(color[to] == 1) {
        fi_node = to;
        la_node = v;
        return true;
      }
    }
    color[v] = 2;
    return false; 
  };

  for (int v = 0; v < g.n; ++v) {
    if (color[v] == 0) {
      if (dfs(dfs, v)) break;
    }
  }

  if (fi_node == -1) {
    return {vector<int>(), vector<int>()};
  }

  vector<int> cycle_nodes;
  vector<int> cycle_edges;
  cycle_nodes.push_back(fi_node);
  cycle_edges.push_back(parent_edge[fi_node]);
  for (int v = la_node; v != fi_node; v = parent[v]) {
    cycle_nodes.push_back(v);
    cycle_edges.push_back(parent_edge[v]);
  }
  cycle_nodes.push_back(fi_node);
  reverse(cycle_nodes.begin(), cycle_nodes.end());
  reverse(cycle_edges.begin(), cycle_edges.end());
  return {cycle_nodes, cycle_edges};
}