#include <bits/stdc++.h>

using namespace std;

#include "../../graph/lca.cpp"


void test_simple(){
  vector<vector<int>> adj = {
    {1, 2},
    {0, 3, 4},
    {0, 6},
    {1},
    {1, 5},
    {4},
    {2},
  };

  Lca lca = Lca(adj, 0);
  assert(lca.lca(5, 6) == 0);
  assert(lca.lca(5, 1) == 1);
  assert(lca.lca(2, 6) == 2);
  assert(lca.lca(3, 5) == 1);
  assert(lca.is_ancestor(0, 1) == true);
  assert(lca.is_ancestor(1, 0) == false);
  assert(lca.kth_ancestor(5, 0) == 5);
  assert(lca.kth_ancestor(5, 1) == 4);
  assert(lca.kth_ancestor(5, 2) == 1);
  assert(lca.kth_ancestor(5, 3) == 0);
  assert(lca.kth_ancestor(5, 4) == -1);
  assert(lca.kth_ancestor(5, 100) == -1);
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