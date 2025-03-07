vector<string> split (const string &s, char sep = ',') {
  vector<string> result = {""};
  for (auto &ch : s) {
    if (ch == sep) {
      result.push_back("");
    } else {
      result.back() += ch;
    }
  }
  return result;
}