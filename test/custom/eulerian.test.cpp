#include <bits/stdc++.h>

using namespace std;

#include "../../graph/graph.cpp"
#include "../../graph/digraph.cpp"
#include "../../graph/undigraph.cpp"
#include "../../graph/eulerian.cpp"


bool is_valid_eulerian_cycle(const Graph<int> &g, int root, vector<int> &res, bool check_cycle = true, bool check_di = true){
  if(root == -1) return false;
  if((int) res.size() != g.m) return false;
  int prev = root;
  for(int i = 0; i < g.m; ++i) {
    auto &e1 = g.edges[res[i]];
    auto &e2 = g.edges[res[(i + 1) % g.m]];
    if(check_di){
      if(i == 0 && e1.from != root) return false;
      if(i < g.m - 1 || check_cycle){
        if(e1.to != e2.from) return false;
      }
    }else{
      if(i == 0 && !(e1.from == root || e1.to == root)) return false;
      if(i < g.m - 1 || check_cycle){
        int nxt = prev ^ e1.from ^ e1.to;
        if(e2.from != nxt && e2.to != nxt) return false;
        prev = nxt;
      }
    }
  }
  set<int> s;
  for(auto &x : res){
    if(x < 0 && x >= g.m) return false;
    s.insert(x);
  }
  if((int) s.size() != g.m) return false;
  return true;
}


void test_digraph_path(){
  int n = 6;
  Digraph<int> g(n);
  g.add(0, 1);
  g.add(1, 2);
  g.add(1, 5);
  g.add(2, 3);
  g.add(3, 4);
  g.add(4, 1);

  auto [root, res] = eulerian(g);
  assert(is_valid_eulerian_cycle(g, root, res, false));
  assert(root == 0);
  vector<int> exp = {0, 1, 3, 4, 5, 2};
  assert(res == exp);
}

void test_digraph_cycle(){
  int n = 3;
  Digraph<int> g(n);
  g.add(0, 1);
  g.add(1, 2);
  g.add(2, 1);
  g.add(1, 0);
  
  auto [root, res] = eulerian(g);
  assert(is_valid_eulerian_cycle(g, root, res));
}

void test_digraph_cycle_large(){
  int n = 6;
  Digraph<int> g(n);
  g.add(0, 1);
  g.add(1, 2);
  g.add(1, 5);
  g.add(2, 3);
  g.add(3, 4);
  g.add(4, 1);
  g.add(5, 0);

  auto [root, res] = eulerian(g);
  assert(is_valid_eulerian_cycle(g, root, res));
}

void test_digraph_no_path(){
  int n = 4;
  Digraph<int> g(n);
  g.add(0, 1);
  g.add(1, 2);
  g.add(0, 2);

  auto [root, res] = eulerian(g);
  assert(root == -1);
  assert(res.empty());
}

void test_undigraph_path(){
  int n = 6;
  Undigraph<int> g(n);
  g.add(0, 1);
  g.add(1, 2);
  g.add(1, 5);
  g.add(2, 3);
  g.add(3, 4);
  g.add(4, 1);

  auto [root, res] = eulerian(g);
  assert(is_valid_eulerian_cycle(g, root, res, false, false));
  assert(root == 0);
  vector<int> exp = {0, 1, 3, 4, 5, 2};
  assert(res == exp);
}

void test_undigraph_cycle(){
  int n = 6;
  Undigraph<int> g(n);
  g.add(0, 1);
  g.add(1, 2);
  g.add(1, 5);
  g.add(2, 3);
  g.add(3, 4);
  g.add(4, 1);
  g.add(0, 5);

  auto [root, res] = eulerian(g);
  assert(is_valid_eulerian_cycle(g, root, res, true, false));
}

void test_undigraph_no_path(){
  int n = 4;
  Undigraph<int> g(n);
  g.add(0, 1);
  g.add(1, 2);
  g.add(2, 3);
  g.add(3, 0);
  g.add(0, 2);
  g.add(1, 3);
  
  auto [root, res] = eulerian(g);
  assert(root == -1);
  assert(res.empty());
}

void test(){
  test_digraph_path();
  test_digraph_cycle();
  test_digraph_cycle_large();
  test_digraph_no_path();
  test_undigraph_path();
  test_undigraph_cycle();
  test_undigraph_no_path();
  cout << "Passed: " << __FILE__ << endl;
}

int main(){	
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << showpoint << setprecision(10);

  test();
}