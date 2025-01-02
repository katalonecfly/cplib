class Twosat {
  public:
    int n;
    Digraph<int> g;

    Twosat(int _n) : n(_n), g(Digraph<int>(2 * _n)) {}

    // add clause: (x_i = val_i)
    void add (int i, int val_i) {
      g.add(2 * i + (val_i ^ 1), 2 * i + val_i);
    }

    // add clause: (x_i = val_i or x_j = val_j)
    void add (int i, int val_i, int j, int val_j) {
      g.add(2 * i + (val_i ^ 1), 2 * j + val_j);
      g.add(2 * j + (val_j ^ 1), 2 * i + val_i);
    }

    pair<bool, vector<int>> satisfiable() {
      auto [C, comp] = strongly_connected_components(g);
      vector<int> res(n);
      for (int i = 0; i < n; ++i) {
        if (comp[2 * i] == comp[2 * i + 1]) {
          return {false, vector<int>()};
        }
        res[i] = (comp[2 * i] < comp[2 * i + 1]);
      }
      return {true, res};
    }
};