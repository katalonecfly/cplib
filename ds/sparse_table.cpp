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
    vector<vector<T>> table;
    F func;

    SparseTable(const vector<T> &a, const F &f) : n((int) a.size()), func(f) {
      if (n == 0) return;
      int lg = floor_log2(n);
      table.resize(lg + 1);
      table[0] = a;
      for (int i = 1; i <= lg; ++i) {
        table[i].resize(n - (1 << i) + 1);
        for (int j = 0; j < (int) table[i].size(); ++j) {
          table[i][j] = func(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
        }
      }
    }

    // [from, to]
    T prod(int from, int to) {
      assert(0 <= from && to < n && from <= to);
      int lg = floor_log2(to - from + 1);
      return func(table[lg][from], table[lg][to - (1 << lg) + 1]);
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