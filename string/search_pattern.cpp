template <typename T>
vector<int> search_pattern (const T &s, const T &p) {
  const int n = (int) s.size();
  const int m = (int) p.size();
  T sp;
  for (auto& x : p) sp.push_back(x);
  for (auto& x : s) sp.push_back(x);
  vector<int> res;
  auto z = z_algorithm(sp);
  for (int i = m; i < n + m; ++i) {
    if (z[i] >= m) {
      res.push_back(i - m);
    }
  }
  return res;
}