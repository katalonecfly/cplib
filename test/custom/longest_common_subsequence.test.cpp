#include <bits/stdc++.h>

using namespace std;

#include "../../dp/longest_common_subsequence.cpp"

void test_vectors(){
  vector<int> a = {3, 1, 3, 2, 7, 4, 8, 2};
  vector<int> b = {6, 5, 1, 2, 3, 4};
  vector<int> lcs = longest_common_subsequence(a, b);
  vector<int> expected = {1, 2, 4};
  assert(lcs == expected); 
}

void test_strings(){
  string a = "AGGTAB";
  string b = "GXTXAYB";
  auto lcs = longest_common_subsequence(vector<char>(a.begin(), a.end()), vector<char>(b.begin(), b.end()));
  vector<char> expected = {'G', 'T', 'A', 'B'};
  assert(lcs == expected); 
}

void test(){
  test_vectors();
  test_strings();
  cout << "Passed: " << __FILE__ << endl;
}

int main(){	
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << showpoint << setprecision(10);

  test();
}