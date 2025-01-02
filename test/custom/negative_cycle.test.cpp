#include <bits/stdc++.h>

using namespace std;

#include "../../graph/graph.cpp"
#include "../../graph/digraph.cpp"
#include "../../graph/negative_cycle.cpp"


void test_simple(){
  int n = 3;

  Digraph<int> g(n);
  g.add(0, 1, -5);
  g.add(1, 2, -6);
  g.add(2, 0, 10);

  vector<int> cycle = negative_cycle(g);
  vector<int> exp = {0, 1, 2};
  assert(!cycle.empty());
  assert(cycle[0] == cycle.back());
  cycle.pop_back();
  bool chk = false;
  for(int i = 0; i < n; ++i){
    bool good = true;
    for(int j = 0; j < n; ++j){
      if(cycle[j] != exp[(i + j) % n]) good = false;
    }
    if(good) chk = true;
  }
  assert(chk);
}

void test_no_negative_cycle(){
  int n = 4;

  Digraph<int> g(n);
  g.add(0, 1, 4);
  g.add(1, 2, 5);
  g.add(2, 0, 10);

  vector<int> cycle = negative_cycle(g);
  assert(cycle.empty());
}

void test(){
  test_simple();
  test_no_negative_cycle();
  cout << "Passed: " << __FILE__ << endl;
}

int main(){	
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << showpoint << setprecision(10);

  test();
}