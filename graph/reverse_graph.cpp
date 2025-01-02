template <typename T>
Digraph<T> reverse_graph(Digraph<T> &g) {
  Digraph<T> g_rev(g.n);
  for (auto &e : g.edges) {
    g_rev.add(e.to, e.from, e.cost);
  }
  return g_rev;
}