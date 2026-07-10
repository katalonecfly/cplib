class DsuPersistent {
  public:
    int n;
    vector<vector<pair<int, int>>> parent_or_size;
    int time = 0;

    DsuPersistent(int _n) : n(_n), parent_or_size(_n + 1, {{-1, 0}}) {}

    int leader(int a, int t) {
      if (parent_or_size[a].back().first >= 0 && parent_or_size[a].back().second <= t) {
        return leader(parent_or_size[a].back().first, t);
      }
      return a;
    }

    bool same(int a, int b, int t) {
      return leader(a, t) == leader(b, t);
    }

    bool merge(int a, int b) {
      time++;
      a = leader(a, time);
      b = leader(b, time);
      if (a == b) return false;
      if (parent_or_size[a].back().first > parent_or_size[b].back().first) {
        swap(a, b);
      }
      parent_or_size[a].push_back({parent_or_size[a].back().first + parent_or_size[b].back().first, time});
      parent_or_size[b].push_back({a, time});
      return true;
    }

    int size(int a, int t) {
      a = leader(a, t);
      int l = 0;
      int r = (int) parent_or_size[a].size() - 1;
      int ans = 0;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (parent_or_size[a][mid].second <= t) {
          ans = mid;
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
      return -parent_or_size[a][ans].first;
    }
};