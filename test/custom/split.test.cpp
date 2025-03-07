#include <bits/stdc++.h>

using namespace std;

#include "../../string/split.cpp"


void test_simple(){
  string s = "qw,123,cxc, bgb g";
  char sep = ',';
  vector<string> expected = {"qw", "123", "cxc", " bgb g"};
  auto splitted = split(s, sep);
  assert(splitted == expected);
  cout << "Passed: " << __func__ << endl;
}

void test_no_separator_in_s(){
  string s = "bvbvffb";
  char sep = ' ';
  vector<string> expected = {"bvbvffb"};
  auto splitted = split(s, sep);
  assert(splitted == expected);
  cout << "Passed: " << __func__ << endl;
}

void test(){
  test_simple();
  test_no_separator_in_s();
  cout << "Passed: " << __FILE__ << endl;
}

int main(){ 
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << showpoint << setprecision(10);

  test();
}