#include <bits/stdc++.h>

using namespace std;

#include "../../graph/graph.cpp"
#include "../../graph/digraph.cpp"
#include "../../graph/topological_sort.cpp"


void test_simple(){
  int n = 8;

  Digraph<int> g(n);
  g.add(0, 1);
  g.add(0, 2);
  g.add(1, 3);
  g.add(2, 3);
  g.add(4, 5);
  g.add(5, 6);

  auto topo = topological_sort(g);
  assert((int) topo.size() == n);
  vector<int> when(n);
  for(int i = 0; i < n; ++i){
    when[topo[i]] = i;
  }

  for(auto &e : g.edges){
    assert(when[e.from] < when[e.to]);
  }
}

void test_no_topo(){
  int n = 4;

  Digraph<int> g(n);
  g.add(0, 1);
  g.add(1, 3);
  g.add(3, 0);
  g.add(0, 2);

  auto topo = topological_sort(g);
  assert((int) topo.size() == 0);
}

void test(){
  test_simple();
  test_no_topo();
  cout << "Passed: " << __FILE__ << endl;
}

int main(){	
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << showpoint << setprecision(10);

  test();
}