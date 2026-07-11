template<typename T>
class FenwickTree {
  public:
    vector<T> data;
    int n;

    FenwickTree() : n(0) {}
    FenwickTree(int _n) : n(_n) {
      data.assign(n, T());
    }
    FenwickTree(vector<T> &a) : FenwickTree((int) a.size()) {
      for (int i = 0; i < n; ++i) {
        data[i] += a[i];
        int r = i | (i + 1);
        if (r < n) data[r] += data[i];
      }
    }

    T sum(int r) {
      T res = 0;
      for(; r >= 0; r = (r & (r + 1)) - 1) {
        res += data[r];
      }
      return res;
    }

    T sum(int l, int r) {
      return sum(r) - sum(l - 1);
    }

    void add(int p, T x) {
      for(; p < n; p = p | (p + 1)) {
        data[p] += x;
      }
    }
};