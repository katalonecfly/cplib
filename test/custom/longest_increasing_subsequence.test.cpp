#include <bits/stdc++.h>

using namespace std;

#include "../../dp/longest_increasing_subsequence.cpp"


void test(){
  vector<int> a1 = {1, 2, 2, 2, 2};
  vector<int> lis1 = longest_increasing_subsequence(a1);
  vector<int> exp1 = {0, 4};
  assert(lis1 == exp1);

  vector<int> a2 = {1, 2, 2, 2, 2};
  vector<int> lis2 = longest_increasing_subsequence(a2, false);
  vector<int> exp2 = {0, 1, 2, 3, 4};
  assert(lis2 == exp2);

  vector<int> a3 = {5, 6, 7, 1, 2, 3};
  vector<int> lis3 = longest_increasing_subsequence(a3);
  vector<int> exp3 = {3, 4, 5};
  assert(lis3 == exp3);

  vector<int> a4 = {10, 11, 5, 6, 7, 1, 8, 2, 3};
  vector<int> lis4 = longest_increasing_subsequence(a4);
  vector<int> exp4 = {2, 3, 4, 6};
  assert(lis4 == exp4);

  cout << "Passed: " << __FILE__ << endl;
}

int main(){	
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << showpoint << setprecision(10);

  test();
}