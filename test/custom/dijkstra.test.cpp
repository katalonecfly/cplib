#include <bits/stdc++.h>

using namespace std;

#include "../../graph/graph.cpp"
#include "../../graph/digraph.cpp"
#include "../../graph/dijkstra.cpp"


void test_simple(){
  int n = 4;

  Digraph<int> g(n);
  g.add(0, 1, 5);
  g.add(1, 3, 7);
  g.add(0, 2, 1);
  g.add(2, 3, 3);

  auto [dist, parent] = dijkstra(g, 0);

  vector<int> exp_dist = {0, 5, 1, 4};
  assert(dist == exp_dist);
  vector<int> exp_parent = {-1, 0, 0, 2};
  assert(parent == exp_parent);
}

void test(){
  test_simple();
  cout << "Passed: " << __FILE__ << endl;
}

int main(){	
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << showpoint << setprecision(10);

  test();
}