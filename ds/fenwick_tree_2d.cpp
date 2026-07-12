template<typename T>
class FenwickTree2D {
  public:
    vector<vector<T>> data;
    int n;
    int m;

    FenwickTree2D() : n(0), m(0) {}
    FenwickTree2D(int _n, int _m) : n(_n), m(_m) {
      data.assign(n, vector<T>(m, T()));
    }

    FenwickTree2D(vector<vector<T>> &a) : FenwickTree2D((int) a.size(), (int) a[0].size()) {
      data = a;
      for (int i = 0; i < n; ++i) {
        int ni = i | (i + 1);
        if (ni < n) {
          for (int j = 0; j < m; ++j) {
            data[ni][j] += data[i][j];
          }
        }
      }
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          int nj = j | (j + 1);
          if (nj < m) {
            data[i][nj] += data[i][j];
          }
        }
      }
    }

    T sum(int x, int y) {
      T res = T();
      for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
        for (int j = y; j >= 0; j = (j & (j + 1)) - 1) {
          res += data[i][j];
        }
      }
      return res;
    }

    T sum(int x1, int y1, int x2, int y2) {
      T res = sum(x2, y2);
      if (x1 > 0) res -= sum(x1 - 1, y2);
      if (y1 > 0) res -= sum(x2, y1 - 1);
      if (x1 > 0 && y1 > 0) res += sum(x1 - 1, y1 - 1);
      return res;
    }

    void add(int x, int y, T val) {
      for (int i = x; i < n; i = i | (i + 1)) {
        for (int j = y; j < m; j = j | (j + 1)) {
          data[i][j] += val;
        }
      }
    }
};