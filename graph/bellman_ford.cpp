template <typename T>
pair<vector<T>, vector<int>> bellman_ford(Graph<T> &g, int start) {
  T INF = numeric_limits<T>::max();
  vector<T> dist(g.n, INF);
  vector<int> parent(g.n, -1);  
  dist[start] = 0;
  int iter = 0;
  while (true) {
    iter += 1;
    bool changed = false;
    for (int v = 0; v < g.n; ++v) {
      if (dist[v] == INF) continue;
      for (auto id : g.g[v]) {
        auto &e = g.edges[id];
        int to = v ^ e.from ^ e.to;
        T cur = dist[e.to];
        T nxt = dist[v] + e.cost;
        if (dist[v] == -INF) nxt = -INF;
        nxt = max(nxt, -INF);
        if (nxt < cur) {
          parent[to] = v;
          changed = true;
          if (iter >= g.n) nxt = -INF;
          dist[to] = nxt;
        }
      }
    }
    if (!changed) break;
  }
  return {dist, parent};
}