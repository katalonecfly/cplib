#include <bits/stdc++.h>

using namespace std;

#include "../../ds/dsu.cpp"
#include "../../graph/graph.cpp"
#include "../../graph/undigraph.cpp"
#include "../../graph/minimum_spanning_tree.cpp"


void test_simple(){
  int n = 6;

  Undigraph<int> g(n);
  g.add(0, 3, 1);
  g.add(1, 4, 2);
  g.add(1, 4, 1);
  g.add(2, 5, 1);
  g.add(0, 1, 20);
  g.add(1, 2, 40);
  g.add(3, 4, 80);
  g.add(4, 5, 70);

  auto [cost, in] = minimum_spanning_tree(g);
  assert(cost == 63);
  vector<bool> exp_in = {1, 0, 1, 1, 1, 1, 0, 0};
  assert(in == exp_in);
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