#include <bits/stdc++.h>

using namespace std;

#include "../../ds/sparse_table.cpp"
#include "../../graph/lca_rmq.cpp"


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

  LcaRmq lca = LcaRmq(adj, 0);
  assert(lca.lca(5, 6) == 0);
  assert(lca.lca(5, 1) == 1);
  assert(lca.lca(2, 6) == 2);
  assert(lca.lca(3, 5) == 1);
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