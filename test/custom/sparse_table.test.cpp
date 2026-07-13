#include <bits/stdc++.h>

using namespace std;

#include "../../ds/sparse_table.cpp"


void test_min(){
  vector<int> v = {3, 8, 1, 5, 4, 5};
  SparseTable st(v, std::min<int>);
  assert(st.prod(1, 3) == 1);
  assert(st.prod(0, 5) == 1);
  assert(st.prod(4, 4) == 4);
  assert(st.prod_index(1, 4) == 2);
}

void test_max(){
  vector<long long> v = {
    123456789123456,
    223456789123456,
    423456789123456,
    5,
    7,
  };
  SparseTable st(v, [](long long lhs, long long rhs) { return max(lhs, rhs); });
  assert(st.prod(0, 2) == 423456789123456);
  assert(st.prod(0, 4) == 423456789123456);
  assert(st.prod(0, 1) == 223456789123456);
  assert(st.prod_index(1, 3) == 2);
}

void test(){
  test_min();
  //test_max();
  cout << "Passed: " << __FILE__ << endl;
}

int main(){	
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << showpoint << setprecision(10);

  test();
}