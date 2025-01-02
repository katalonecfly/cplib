#pragma once

class Dsu {
  public:
    int n;
    vector<int> parent_or_size;

    Dsu(int _n) : n(_n), parent_or_size(_n, -1) {}

    int leader(int a) {
      if (parent_or_size[a] < 0) return a;
      return parent_or_size[a] = leader(parent_or_size[a]);
    }

    bool same(int a, int b) {
      return leader(a) == leader(b);
    }

    int merge(int a, int b) {
      int la = leader(a);
      int lb = leader(b);
      if (la == lb) return la;
      if (-parent_or_size[la] < -parent_or_size[lb]) swap(la, lb);
      parent_or_size[la] += parent_or_size[lb];
      parent_or_size[lb] = la;
      return la;
    }

    int size(int a) {
      return -parent_or_size[leader(a)];
    }

    vector<vector<int>> components() {
      vector<int> leader_buf(n), comp_size(n, 0);
      for (int i = 0; i < n; ++i) {
        leader_buf[i] = leader(i);
        comp_size[leader_buf[i]]++;
      }
      vector<vector<int>> ans(n);
      for (int i = 0; i < n; ++i) {
        ans[i].reserve(comp_size[i]);
      }
      for (int i = 0; i < n; ++i) {
        ans[leader_buf[i]].push_back(i);
      }
      ans.erase(
        remove_if(ans.begin(), ans.end(), [&](const vector<int> &v) { return v.empty(); }),
        ans.end()
      );
      return ans;
    }
};