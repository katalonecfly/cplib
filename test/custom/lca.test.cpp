#include <bits/stdc++.h>

using namespace std;

#include "../../graph/lca.cpp"


void test_simple(){
  /*
          0
        /   \
       1     2
      / \     \
     3   4     6
          \
           5
  */
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
  assert(lca.lca(1, 1) == 1);
  assert(lca.is_ancestor(0, 1) == true);
  assert(lca.is_ancestor(1, 0) == false);
  assert(lca.kth_ancestor(5, 0) == 5);
  assert(lca.kth_ancestor(5, 1) == 4);
  assert(lca.kth_ancestor(5, 2) == 1);
  assert(lca.kth_ancestor(5, 3) == 0);
  assert(lca.kth_ancestor(5, 4) == -1);
  assert(lca.kth_ancestor(5, 100) == -1);
  assert(lca.distance(1, 1) == 0);
  assert(lca.distance(1, 5) == 2);
  assert(lca.distance(5, 1) == 2);
  assert(lca.distance(3, 5) == 3);
  assert(lca.distance(5, 6) == 5);
  pair<int, pair<int, int>> diameter1 = {5, {5, 6}};
  pair<int, pair<int, int>> diameter2 = {5, {6, 5}};
  assert(lca.diameter() == diameter1 || lca.diameter() == diameter2);
  assert(lca.on_path(1, 3, 5) == true);
  assert(lca.on_path(4, 3, 5) == true);
  assert(lca.on_path(2, 3, 5) == false);
  assert(lca.on_path(1, 1, 1) == true);
  assert(lca.kth_node_on_path(6, 5, 0) == 6);
  assert(lca.kth_node_on_path(6, 5, 1) == 2);
  assert(lca.kth_node_on_path(6, 5, 2) == 0);
  assert(lca.kth_node_on_path(6, 5, 3) == 1);
  assert(lca.kth_node_on_path(6, 5, 4) == 4);
  assert(lca.kth_node_on_path(6, 5, 5) == 5);
  assert(lca.kth_node_on_path(6, 5, 6) == -1);
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