#include <bits/stdc++.h>

using namespace std;

#include "../../graph/graph.cpp"
#include "../../graph/digraph.cpp"
#include "../../graph/find_cycle_di.cpp"


void test_simple(){
  int n = 4;

  Digraph<int> g(n);
  g.add(0, 1, 7);
  g.add(1, 2, 8);
  g.add(2, 3, 5);
  g.add(3, 0, 6);

  auto [cycle_v, cycle_e] = find_cycle_di(g);
  
  assert(cycle_v[0] == cycle_v.back());
  assert((int) cycle_v.size() == (int) cycle_e.size() + 1);
  for(int i = 0; i < (int) cycle_v.size() - 1; ++i){
    int v1 = cycle_v[i];
    int to1 = cycle_v[i + 1];
    auto &e = g.edges[cycle_e[i]];
    int v2 = e.from;
    int to2 = e.to;
    assert((v1 == v2 && to1 == to2) || (v1 == to2 && to1 == v2));
  }
}

void test_no_cycle(){
  int n = 5;

  Digraph<int> g(n);
  g.add(0, 1, 7);
  g.add(1, 2, 8);
  g.add(2, 3, 5);

  auto [cycle_v, cycle_e] = find_cycle_di(g);
  assert(cycle_v.empty());
  assert(cycle_e.empty());  
}


void test(){
  test_simple();
  test_no_cycle();
  cout << "Passed: " << __FILE__ << endl;
}

int main(){	
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << showpoint << setprecision(10);

  test();
}