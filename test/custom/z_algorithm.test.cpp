#include <bits/stdc++.h>

using namespace std;

#include "../../string/z_algorithm.cpp"


void test(){
  string s1 = "aaaaaa";
  vector<int> z1 = z_algorithm(s1);
  vector<int> exp1 = {6, 5, 4, 3, 2, 1};
  assert(z1 == exp1);

  string s2 = "aaabaab";
  vector<int> z2 = z_algorithm(s2);
  vector<int> exp2 = {7, 2, 1, 0, 2, 1, 0};
  assert(z2 == exp2);

  string s3 = "zbzczbz";
  vector<int> z3 = z_algorithm(s3);
  vector<int> exp3 = {7, 0, 1, 0, 3, 0, 1};
  assert(z3 == exp3);

  vector<int> s4 = {1, 2, 3, 1, 2, 3};
  vector<int> z4 = z_algorithm(s4);
  vector<int> exp4 = {6, 0, 0, 3, 0, 0};
  assert(z4 == exp4);

  cout << "Passed: " << __FILE__ << endl;
}

int main(){	
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << showpoint << setprecision(10);

  test();
}