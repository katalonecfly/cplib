#pragma once

template <typename T>
class Graph {
  public:
    struct Edge {
      int from;
      int to;
      T cost;
    };

    int n;
    int m;
    vector<vector<int>> g;
    vector<Edge> edges;

    Graph(int _n) : n(_n) {
      m = 0;
      g.resize(_n);
    };

    virtual int add(int from, int to, T cost) = 0;
};