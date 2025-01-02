#pragma once

template <typename T>
class Undigraph : public Graph<T> {
  public:
    using Graph<T>::n;
    using Graph<T>::m;
    using Graph<T>::g;
    using Graph<T>::edges;
    
    Undigraph(int n) : Graph<T>(n) {}

    int add(int from, int to, T cost = 1) {
      assert(0 <= from && from < n && 0 <= to && to < n);
      int id = (int) edges.size();
      g[from].push_back(id);
      g[to].push_back(id);
      edges.push_back({from, to, cost});
      ++m;
      return id;
    }
};