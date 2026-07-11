#include <bits/stdc++.h>

using namespace std;

#include "../../ds/fenwick_tree.cpp"


void test_simple(){
  int n = 5;
  FenwickTree<int> fenw(n);
  fenw.add(0, 3);
  fenw.add(4, 5);
  fenw.add(2, -1);
  assert(fenw.sum(0, 4) == 7);
  assert(fenw.sum(0, 0) == 3);
  assert(fenw.sum(1, 1) == 0);
  assert(fenw.sum(2, 4) == 4);
  assert(fenw.sum(1) == 3);
}

void test_init(){
  int n = 5;
  vector<int> init = {4, 3, 1, -5, 0};
  FenwickTree<int> fenw(init);
  assert(fenw.sum(0, 4) == 3);
  fenw.add(0, 2);
  fenw.add(1, 2);
  fenw.add(2, -2);
  assert(fenw.sum(0, 4) == 5);
  assert(fenw.sum(0, 0) == 6);
  assert(fenw.sum(1, 1) == 5);
  assert(fenw.sum(2, 4) == -6);
}

void test(){
  test_simple();
  test_init();
  cout << "Passed: " << __FILE__ << endl;
}

int main(){	
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << showpoint << setprecision(10);

  test();
}