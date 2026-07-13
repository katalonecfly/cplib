/*
  SparseTable st(v, std::min<int>);
  SparseTable st(v, std::max<long long>);
  SparseTable st(v, [](int lhs, int rhs) { return min(lhs, rhs); });
  SparseTable st(v, [](long long lhs, long long rhs) { return max(lhs, rhs); });
*/
template<typename T, typename F>
class SparseTable {
  public:
    int n;
    vector<T> a;
    vector<vector<T>> table;
    F func;

    SparseTable() = default;

    SparseTable(const vector<T> &v, const F &f) : n((int) v.size()), a(v), func(f) {
      if (n == 0) return;
      int lg = floor_log2(n);
      table.resize(lg + 1);
      table[0].resize(n);
      iota(table[0].begin(), table[0].end(), 0);
      for (int i = 1; i <= lg; ++i) {
        table[i].resize(n - (1 << i) + 1);
        for (int j = 0; j < (int) table[i].size(); ++j) {
          int x = table[i - 1][j];
          int y = table[i - 1][j + (1 << (i - 1))];
          // leftmost on ties
          table[i][j] = (func(a[x], a[y]) == a[x] ? x : y);
        }
      }
    }

    // index of min/max on [from, to]
    int prod_index (int from, int to) {
      assert(0 <= from && from <= to && to < n);
      int lg = floor_log2(to - from + 1);
      int x = table[lg][from];
      int y = table[lg][to - (1 << lg) + 1];
      return (func(a[x], a[y]) == a[x] ? x : y);
    }

    // value of min/max on [from, to]
    T prod(int from, int to) {
      return a[prod_index(from, to)];
    }

  private:
    int floor_log2(int x) {
      return 31 - __builtin_clz(x);
    }
};

template<typename T>
SparseTable(std::vector<T>, T(*)(T, T)) -> SparseTable<T, T(*)(T, T)>;

template<typename T>
SparseTable(std::vector<T>, const T&(*)(const T&, const T&)) -> SparseTable<T, const T&(*)(const T&, const T&)>;