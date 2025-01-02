/*
  Indices of longest (strictly) increasing subsequence.
  If several of same length - return the last one.
*/
template <typename T>
vector<int> longest_increasing_subsequence (const vector<T> &a, bool strictly = true) {
  const int n = (int) a.size();
  if (n == 0) return {};
  vector<int> prev(n);
  vector<pair<T, int>> dp;
  for (int i = 0; i < n; ++i) {
    pair<T, int> val = {a[i], strictly ? 0 : i};
    int pos = distance(dp.begin(), lower_bound(dp.begin(), dp.end(), val));
    if (pos == (int) dp.size()) {
      dp.push_back({a[i], i});
    } else {
      dp[pos] = {a[i], i};
    }
    prev[i] = (pos == 0 ? 0 : dp[pos - 1].second);
  }

  // restore indices
  int len = (int) dp.size();
  int cur = dp.back().second;
  vector<int> lis(len);
  while (len--) {
    lis[len] = cur;
    cur = prev[cur];
  }
  return lis;
}