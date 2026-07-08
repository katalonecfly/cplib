#include <bits/stdc++.h>

using namespace std;

#include "../../graph/graph.cpp"
#include "../../graph/undigraph.cpp"
#include "../../graph/bridges.cpp"


void test_simple(){
  int n = 7;

  Undigraph<int> g(n);
  g.add(0, 1);
  g.add(0, 2);
  g.add(1, 2);
  g.add(2, 3);
  g.add(3, 4);
  g.add(4, 5);
  g.add(3, 5);
  g.add(5, 6);

  vector<bool> expected_is_bridge = {0, 0, 0, 1, 0, 0, 0, 1};
  auto is_bridge = find_bridges(g);
  assert(is_bridge == expected_is_bridge);
}

void test_no_bridges(){
  int n = 3;

  Undigraph<int> g(n);
  g.add(0, 1);
  g.add(0, 2);
  g.add(1, 2);

  vector<bool> expected_is_bridge = {0, 0, 0};
  auto is_bridge = find_bridges(g);
  assert(is_bridge == expected_is_bridge);
}

void test_multiple_edges(){
  int n = 7;

  Undigraph<int> g(n);
  g.add(0, 1);
  g.add(0, 2);
  g.add(1, 2);
  g.add(2, 3);
  g.add(3, 4);
  g.add(4, 5);
  g.add(3, 5);
  g.add(5, 6);
  g.add(5, 6);

  vector<bool> expected_is_bridge = {0, 0, 0, 1, 0, 0, 0, 0, 0};
  auto is_bridge = find_bridges(g);
  assert(is_bridge == expected_is_bridge);
}

void test(){
  test_simple();
  test_no_bridges();
  test_multiple_edges();
  cout << "Passed: " << __FILE__ << endl;
}

int main(){	
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << showpoint << setprecision(10);

  test();
}