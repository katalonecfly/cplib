#include <bits/stdc++.h>

using namespace std;

#include "../../string/z_algorithm.cpp"
#include "../../string/search_pattern.cpp"


void test(){
  string s1 = "aaaaaa";
  string p1 = "aa";
  vector<int> z1 = search_pattern(s1, p1);
  vector<int> exp1 = {0, 1, 2, 3, 4};
  assert(z1 == exp1);

  string s2 = "ababa";
  string p2 = "aba";
  vector<int> z2 = search_pattern(s2, p2);
  vector<int> exp2 = {0, 2};
  assert(z2 == exp2);

  string s3 = "abcde";
  string p3 = "xx";
  vector<int> z3 = search_pattern(s3, p3);
  vector<int> exp3 = {};
  assert(z3 == exp3);

  cout << "Passed: " << __FILE__ << endl;
}

int main(){	
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << showpoint << setprecision(10);

  test();
}