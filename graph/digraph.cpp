#pragma once

template <typename T>
class Digraph : public Graph<T> {
  public:
    using Graph<T>::n;
    using Graph<T>::m;
    using Graph<T>::g;
    using Graph<T>::edges;
    
    vector<int> indeg;
    vector<int> outdeg;

    Digraph(int n) : Graph<T>(n) {}

    int add(int from, int to, T cost = 1) {
      assert(0 <= from && from < n && 0 <= to && to < n);
      int id = (int) edges.size();
      g[from].push_back(id);
      edges.push_back({from, to, cost});
      ++m;
      return id;
    }

    void calc_inout_deg() {
      assert(indeg.empty() && outdeg.empty());
      indeg.resize(n);
      outdeg.resize(n);
      for(auto &e : edges) {
        ++indeg[e.to];
        ++outdeg[e.from];
      }
    }

    pair<vector<int>, vector<int>> get_inout_deg() {
      if(indeg.empty()) calc_inout_deg();
      return {indeg, outdeg};
    }
};