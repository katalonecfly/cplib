template <typename T>
pair<T, vector<bool>> minimum_spanning_tree(Undigraph<T> &g) {
  vector<int> order(g.m);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](const int &lhs, const int &rhs){
    return g.edges[lhs].cost < g.edges[rhs].cost;
  });

  T mst_cost = T(0);
  vector<bool> in_mst(g.m, false);
  Dsu dsu(g.n);
  for (int id : order) {
    auto &e = g.edges[id];
    if (!dsu.same(e.from, e.to)) {
      mst_cost += e.cost;
      in_mst[id] = true;
      dsu.merge(e.from, e.to);
    }
  }
  return {mst_cost, in_mst};
}