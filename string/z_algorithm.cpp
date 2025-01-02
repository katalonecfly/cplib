template <typename T>
vector<int> z_algorithm(const T &s) {
  const int n = (int) s.size();
  if (n == 0) return {};
  vector<int> z(n);
  z[0] = 0;
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    z[i] = (i > r ? 0 : min(r - i + 1, z[i - l]));
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
  z[0] = n;
  return z;
}