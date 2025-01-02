template <typename T>
pair<vector<T>, vector<int>> dijkstra(Graph<T> &g, int start) {
  vector<T> dist(g.n, numeric_limits<T>::max());
  vector<int> parent(g.n, -1);
  priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;
  dist[start] = 0;
  pq.emplace(dist[start], start);
  while (!pq.empty()) {
    auto [dv, v] = pq.top();
    pq.pop();
    if (dv > dist[v]) continue;
    for (auto id : g.g[v]) {
      auto &e = g.edges[id];
      int to = v ^ e.from ^ e.to;
      if (dist[v] + e.cost < dist[to]) {
        dist[to] = dist[v] + e.cost;
        parent[to] = v;
        pq.emplace(dist[to], to);
      }
    }
  }
  return {dist, parent};
}