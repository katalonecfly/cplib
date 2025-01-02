template <typename T>
pair<int, vector<int>> eulerian(const Graph<T> &g) {
  vector<int> in_deg(g.n, 0);
  vector<int> out_deg(g.n, 0);
  for (int id = 0; id < (int) g.edges.size(); ++id) {
    auto &e = g.edges[id];
    in_deg[e.to]++;
    out_deg[e.from]++;
  }
  
  int root = -1;
  int odd = 0;
  for (int i = 0; i < g.n; ++i) {
    if ((in_deg[i] + out_deg[i]) % 2 == 1) {
      ++odd;
      if (root == -1 || (out_deg[i] - in_deg[i] > out_deg[root] - in_deg[root])) {
        root = i;
      }
    }
  }

  if (odd > 2) {
    return {-1, vector<int>()};
  }

  if (root == -1) {
    root = 0;
    while (root < g.n && in_deg[root] + out_deg[root] == 0) {
      ++root;
    }
    if (root == g.n) {
      return {0, vector<int>()};
    }
  }

  vector<bool> used(g.m, false);
  vector<int> ptr(g.n, 0);
  vector<int> balance(g.n, 0);
  vector<int> res(g.m);
  int stack_ptr = 0;
  int res_ptr = g.m;
  int v = root;
  while (true) {
    bool found = false;
    while (ptr[v] < (int) g.g[v].size()) {
      int id = g.g[v][ptr[v]++];
      if (used[id]) continue;
      used[id] = true;
      res[stack_ptr++] = id;
      auto &e = g.edges[id];
      balance[v]++;
      int to = v ^ e.from ^ e.to;
      v = to;
      balance[v]--;
      found = true;
      break;
    }
    if (!found) {
      if (stack_ptr == 0) break;
      int id = res[--stack_ptr];
      res[--res_ptr] = id;
      auto &e = g.edges[id];
      int to = v ^ e.from ^ e.to;
      v = to;
    }
  }

  int disbalance = 0;
  for_each(balance.begin(), balance.end(), [&](int b) {
    disbalance += abs(b);
  });
  if (res_ptr != 0 || disbalance > 2) {
    return {-1, vector<int>()};
  }
  return {root, res};
}