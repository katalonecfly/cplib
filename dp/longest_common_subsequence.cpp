template <typename T>
vector<T> longest_common_subsequence (const vector<T> &a, const vector<T> &b) {
  const int na = (int) a.size();
  const int nb = (int) b.size();
  if (na == 0 || nb == 0) return {};
  vector<vector<int>> dp(na + 1, vector<int>(nb + 1, numeric_limits<int>::max()));
  for (int i = 0; i <= na; ++i) {
    for (int j = 0; j <= nb; ++j) {
      if (i == 0 || j == 0) {
        dp[i][j] = 0;
      } else if (a[i - 1] == b[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
      }
    }
  }

  // restore
  int i = na;
  int j = nb;
  int ind = dp[na][nb];
  vector<T> ans(ind);
  while (i > 0 && j > 0) {
    if (a[i - 1] == b[j - 1]) {
      ans[ind - 1] = a[i - 1];
      --i;
      --j;
      --ind;
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
      --i;
    } else{
      --j;
    }
  }
  return ans;
}