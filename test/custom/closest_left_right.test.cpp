#include <bits/stdc++.h>

using namespace std;

#include "../../misc/closest_left_right.cpp"


void test_closest_left(){
  vector<int> a = {1, 5, 2, 4, 7, 8, 2, 2, 0};
  
  vector<int> expected_less = {-1, 0, 0, 2, 3, 4, 0, 0, -1};
  auto result_less = closest_left(a, less<int>());
  assert(result_less == expected_less);

  vector<int> expected_less_equal = {-1, 0, 0, 2, 3, 4, 2, 6, -1};
  auto result_less_equal = closest_left(a, less_equal<int>());
  assert(result_less_equal == expected_less_equal);

  vector<int> expected_greater = {-1, -1, 1, 1, -1, -1, 5, 5, 7};
  auto result_greater = closest_left(a, greater<int>());
  assert(result_greater == expected_greater);

  vector<int> expected_greater_equal = {-1, -1, 1, 1, -1, -1, 5, 6, 7};
  auto result_greater_equal = closest_left(a, greater_equal<int>());
  assert(result_greater_equal == expected_greater_equal);
}

void test_closest_right(){
  vector<int> a = {1, 5, 2, 4, 7, 8, 2, 2, 0};
  
  vector<int> expected_less = {8, 2, 8, 6, 6, 6, 8, 8, 9};
  auto result_less = closest_right(a, less<int>());
  assert(result_less == expected_less);
}

void test(){
  test_closest_left();
  test_closest_right();
  cout << "Passed: " << __FILE__ << endl;
}

int main(){ 
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << showpoint << setprecision(10);

  test();
}