#include <bits/stdc++.h>

using namespace std;

#include "../../graph/graph.cpp"
#include "../../graph/digraph.cpp"
#include "../../graph/reverse_graph.cpp"


void test(){
  int n = 4;
  Digraph<int> g(n);
  g.add(0, 1, 5);
  g.add(1, 0, 3);
  g.add(2, 3, 1);
  g.add(0, 3, 7);
  g.add(3, 2, 6);

  auto g_rev = reverse_graph(g);
  assert(g.n == g_rev.n);
  assert(g.m == g_rev.m);
  for(int id = 0; id < g.m; ++id){
    auto &e = g.edges[id];
    auto &e_rev = g_rev.edges[id];
    assert(e.from == e_rev.to);
    assert(e.to == e_rev.from);
    assert(e.cost == e_rev.cost);
  }

  cout << "Passed: " << __FILE__ << endl;
}

int main(){	
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << showpoint << setprecision(10);

  test();
}