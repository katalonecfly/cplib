template <typename T>
vector<vector<T>> floyd_warshall(Graph<T> &g) {
  vector<vector<T>> dist(g.n, vector<T>(g.n, numeric_limits<T>::max()));
  for (int v = 0; v < g.n; ++v) {
    dist[v][v] = 0;
    for (auto id : g.g[v]) {
      auto &e = g.edges[id];
      int to = v ^ e.from ^ e.to;
      dist[v][to] = min(dist[v][to], e.cost);
    }
  }

  for (int k = 0; k < g.n; ++k) {
    for (int i = 0; i < g.n; ++i) {
      if (dist[i][k] == numeric_limits<T>::max()) continue;
      for (int j = 0; j < g.n; ++j){
        if (dist[k][j] == numeric_limits<T>::max()) continue;
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  return dist;
}