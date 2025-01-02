#include <bits/stdc++.h>

using namespace std;

#include "../../string/trie.cpp"


void test(){
  vector<string> words = {
    "abc",
    "ab",
    "xxx",
    "yy",
    "yy",
    "yyy",
  };
  vector<tuple<string, int, vector<int>>> queries = {
    {"a", 2, {}},
    {"t", 0, {}},
    {"abc", 1, {0}},
    {"abd", 0, {}},
    {"ab", 2, {1}},
    {"yy", 3, {3, 4}},
  };

  Trie<26, 'a'> trie;
  for(auto &s : words){
    trie.insert(s);
  }
  for(auto &[s, exp_cnt, exp_here] : queries){
    int ans_cnt = trie.count(s);
    assert(exp_cnt == ans_cnt);
    int cur = trie.find(s);
    assert(exp_here == trie.nodes[cur].here);
  }

  cout << "Passed: " << __FILE__ << endl;
}

int main(){	
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << showpoint << setprecision(10);

  test();
}