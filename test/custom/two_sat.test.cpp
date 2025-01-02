#include <bits/stdc++.h>

using namespace std;

#include "../../graph/graph.cpp"
#include "../../graph/digraph.cpp"
#include "../../graph/strongly_connected_components.cpp"
#include "../../graph/two_sat.cpp"


void test_simple_true(){
  int n = 3;

  Twosat twosat(n);
  // (x_0 or !x_1) and (!x_0 or !x_1) and (x_1 or x_2) and (x_0 or x_0)
  twosat.add(0, 1, 1, 0);
  twosat.add(0, 0, 1, 0);
  twosat.add(1, 1, 2, 1);
  twosat.add(0, 1, 0, 1);

  auto [is, vals] = twosat.satisfiable();
  assert(is);
  vector<int> exp = {1, 0, 1};
  assert(vals == exp);
}

void test_simple_false(){
  int n = 3;

  Twosat twosat(n);
  // (x_0 or !x_1) and (!x_0 or !x_1) and (x_1 or x_2) and (x_0) and (!x_0 or x_1)
  twosat.add(0, 1, 1, 0);
  twosat.add(0, 0, 1, 0);
  twosat.add(1, 1, 2, 1);
  twosat.add(0, 1);
  twosat.add(0, 0, 1, 1);

  auto [is, vals] = twosat.satisfiable();
  assert(!is);
  assert(vals.empty());
}

void test(){
  test_simple_true();
  test_simple_false();
  cout << "Passed: " << __FILE__ << endl;
}

int main(){	
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << showpoint << setprecision(10);

  test();
}