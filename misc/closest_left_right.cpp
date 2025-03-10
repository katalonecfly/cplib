/*
  for every pos i, find largest j < i (or j <= i) such that compare(a[j], a[i]) is true, or -1 if no such j
  compare: less<int>(), greater<int>(), less_equal<int>(), greater_equal<int>()
  usage: auto res = closest(a, less<int>())
*/
template<typename T, typename C>
vector<int> closest_left (const vector<T> &a, C &&compare) {
  const int n = (int) a.size();
  vector<int> res(n);
  stack<int> st;
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && !compare(a[st.top()], a[i])) {
      st.pop();
    }
    res[i] = st.empty() ? -1 : st.top();
    st.push(i);
  }
  return res;
}

/*
  for every pos i, find smallest j > i (or j >= i) such that compare(a[j], a[i]) is true, or 'size of a' if no such j
*/
template<typename T, typename C>
vector<int> closest_right (const vector<T> &a, C &&compare) {
  const int n = (int) a.size();
  vector<int> res(n);
  stack<int> st;
  for (int i = n - 1; i >= 0; --i) {
    while (!st.empty() && !compare(a[st.top()], a[i])) {
      st.pop();
    }
    res[i] = st.empty() ? n : st.top();
    st.push(i);
  }
  return res;
}