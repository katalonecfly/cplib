#include <bits/stdc++.h>

using namespace std;

#include "../../ds/dsu_persistent.cpp"


void test_simple(){
  int n = 5;
  DsuPersistent dsup(n);

  dsup.merge(0, 1);
  dsup.merge(2, 3);
  dsup.merge(2, 4);
  dsup.merge(3, 4);
  dsup.merge(0, 4);

  assert(dsup.same(0, 1, 0) == false);
  assert(dsup.same(0, 1, 1) == true);
  assert(dsup.same(1, 4, 4) == false);
  assert(dsup.same(1, 4, 5) == true);
  assert(dsup.same(1, 4, 100) == true);
  assert(dsup.size(0, 0) == 1);
  assert(dsup.size(0, 1) == 2);
  assert(dsup.size(0, 2) == 2);
  assert(dsup.size(0, 3) == 2);
  assert(dsup.size(0, 4) == 2);
  assert(dsup.size(0, 5) == 5);
  assert(dsup.size(0, 100) == 5);
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