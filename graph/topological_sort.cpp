template <typename T>
vector<int> topological_sort(Digraph<T> &g) {
  auto [indeg, outdeg] = g.get_inout_deg(); 
  
  vector<int> topo;
  for (int v = 0; v < g.n; ++v) {
    if (indeg[v] == 0) topo.push_back(v);
  }

  for (int i = 0; i < (int) topo.size(); ++i) {
    int v = topo[i];
    for (auto id : g.g[v]) {
      int to = g.edges[id].to;
      --indeg[to];
      if (indeg[to] == 0) {
        topo.push_back(to);
      }
    }
  }

  return (int) topo.size() == g.n ? topo : vector<int>();
}