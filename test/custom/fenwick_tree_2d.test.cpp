#include <bits/stdc++.h>

using namespace std;

#include "../../ds/fenwick_tree_2d.cpp"


void test_simple(){
  int n = 3;
  int m = 2;
  FenwickTree2D<int> fenw(n, m);
  fenw.add(0, 0, 5);
  fenw.add(1, 1, 10);
  assert(fenw.sum(0, 0, n - 1, m - 1) == 15);
  assert(fenw.sum(n - 1, m - 1) == 15);
  assert(fenw.sum(1, 1, n - 1, m - 1) == 10);
  fenw.add(2, 1, -3);
  assert(fenw.sum(1, 1, n - 1, m - 1) == 7);
}

void test_init(){
  int n = 2;
  int m = 3;
  vector<vector<long long>> a = {
    {5, 6, 7},
    {-1, 100, -2},
  };
  FenwickTree2D<long long> fenw(a);
  assert(fenw.sum(n - 1, m - 1) == 115);
  fenw.add(1, 1, 7);
  assert(fenw.sum(0, 1, 1, 1) == 113);
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