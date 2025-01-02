template <int alph_size, char base>
class Trie {
  public:
    struct Node {
      array<int, alph_size> nxt;
      int cnt;
      vector<int> here;

      Node() {
        cnt = 0;
        nxt.fill(-1);
      }
    };

    vector<Node> nodes;
    
    Trie() {
      nodes.push_back(Node());
    }

    void insert (const string &s, int id) {
      int cur = 0;
      for (auto &ch : s) {
        int ind = ch - base;
        int to = nodes[cur].nxt[ind];
        if (to == -1) {
          to = (int) nodes.size();
          nodes[cur].nxt[ind] = to;
          nodes.push_back(Node());
        }
        nodes[cur].cnt++;
        cur = to;
      }
      nodes[cur].cnt++;
      nodes[cur].here.push_back(id);
    }

    void insert (const string &s) {
      insert(s, nodes[0].cnt);
    }

    int find (const string &s) {
      int cur = 0;
      for (auto &ch : s) {
        int ind = ch - base;
        cur = nodes[cur].nxt[ind];
        if (cur == -1) break;
      }
      return cur;
    }

    int count (const string &s) {
      int cur = find(s);
      return cur == -1 ? 0 : nodes[cur].cnt;
    }
};