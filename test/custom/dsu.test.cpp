#include <bits/stdc++.h>

using namespace std;

#include "../../ds/dsu.cpp"


void test_simple(){
  int n = 7;
  Dsu dsu(n);

  assert(!dsu.same(0, 1));
  dsu.merge(0, 1);
  assert(dsu.same(0, 1));

  dsu.merge(4, 5);
  dsu.merge(0, 4);
  assert(dsu.same(5, 1));
  assert(dsu.size(1) == 4);
  dsu.merge(2, 3);

  auto comp = dsu.components();
  for(auto &v : comp){
    sort(v.begin(), v.end());
  }
  sort(comp.begin(), comp.end());
  vector<vector<int>> exp = {
    {0, 1, 4, 5},
    {2, 3},
    {6},
  };
  assert(comp == exp);
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