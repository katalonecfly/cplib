#include <bits/stdc++.h>

using namespace std;

#include "../../graph/graph.cpp"
#include "../../graph/undigraph.cpp"
#include "../../graph/digraph.cpp"
#include "../../graph/floyd_warshall.cpp"


void test_undigraph(){
  int n = 4;

  Undigraph<int> g(n);
  g.add(0, 1, 1);
  g.add(1, 2, 4);
  g.add(0, 2, 8);

  auto dist = floyd_warshall(g);

  int INF = numeric_limits<int>::max();
  vector<vector<int>> exp_dist = {
    {0, 1, 5, INF},
    {1, 0, 4, INF},
    {5, 4, 0, INF},
    {INF, INF, INF, 0},
  };
  assert(dist == exp_dist);
}

void test_digraph(){
  int n = 4;

  Digraph<int> g(n);
  g.add(0, 1, 1);
  g.add(1, 2, 4);
  g.add(0, 2, 8);

  auto dist = floyd_warshall(g);

  int INF = numeric_limits<int>::max();
  vector<vector<int>> exp_dist = {
    {0, 1, 5, INF},
    {INF, 0, 4, INF},
    {INF, INF, 0, INF},
    {INF, INF, INF, 0},
  };
  assert(dist == exp_dist);
}

void test(){
  test_undigraph();
  test_digraph();
  cout << "Passed: " << __FILE__ << endl;
}

int main(){	
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << showpoint << setprecision(10);

  test();
}