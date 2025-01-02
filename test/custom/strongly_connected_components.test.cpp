#include <bits/stdc++.h>

using namespace std;

#include "../../graph/graph.cpp"
#include "../../graph/digraph.cpp"
#include "../../graph/reverse_graph.cpp"
#include "../../graph/strongly_connected_components.cpp"


void test_simple(){
  int n = 8;

  Digraph<int> g(n);
  g.add(0, 1);
  g.add(1, 0);
  g.add(2, 3);
  g.add(3, 4);
  g.add(4, 2);
  g.add(6, 7);
  g.add(7, 6);
  g.add(0, 2);
  g.add(2, 6);
  g.add(4, 5);

  auto [C, comp] = strongly_connected_components(g);
  vector<int> exp = {0, 0, 1, 1, 1, 2, 3, 3};
  assert(C == 4);
  for(int i = 0; i < g.n; ++i){
    assert(0 <= comp[i] && comp[i] < C);
    for(int j = i + 1; j < g.n; ++j){
      assert((comp[i] == comp[j] && exp[i] == exp[j]) || (comp[i] != comp[j] && exp[i] != exp[j]));
    }
  }
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