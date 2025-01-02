template <typename T>
vector<int> negative_cycle(Digraph<T> &g) {
  T INF = numeric_limits<T>::max();
  vector<T> dist(g.n, 0);
  vector<int> parent(g.n, -1);  
  int node;
  for (int i = 0; i < g.n; ++i) {
    node = -1;
    for (int v = 0; v < g.n; ++v) {
      if (dist[v] == INF) continue;
      for (auto id : g.g[v]) {
        auto &e = g.edges[id];
        int to = v ^ e.from ^ e.to;
        T cur = dist[e.to];
        T nxt = dist[v] + e.cost;
        if (nxt < cur) {
          parent[to] = v;
          node = to;
          dist[to] = max(-INF, nxt);
        }
      }
    }
  }

  if (node == -1) {
    return vector<int>();
  }

  for (int i = 0; i < g.n; ++i) node = parent[node];
  vector<int> cycle;
  for (int v = node;; v = parent[v]) {
    cycle.push_back(v);
    if (v == node && cycle.size() > 1) break;
  }
  reverse(cycle.begin(), cycle.end());
  return cycle;
}