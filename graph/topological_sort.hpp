#pragma once

class TopologicalSort {
 private:
  bool init;
  int n;
  vector<vector<int>> g;
  vector<int> p;

 public:
  TopologicalSort() : TopologicalSort(0) {}
  TopologicalSort(int _n) : init(false), n(_n), g(_n) {}

  void add_edge(int u, int v) {
    assert(!init);

    g[u].push_back(v);
  }

  bool build() {
    assert(!init);
    init = true;

    vector<int> cnt(n);
    for (int v = 0; v < n; v++) {
      for (int nv : g[v]) {
        cnt[nv]++;
      }
    }
    queue<int> que;
    for (int v = 0; v < n; v++) {
      if (cnt[v] == 0) {
        que.push(v);
      }
    }
    while (!que.empty()) {
      int v = que.front();
      que.pop();
      p.push_back(v);
      for (int nv : g[v]) {
        cnt[nv]--;
        if (cnt[nv] == 0) {
          que.push(nv);
        }
      }
    }
    if (n != int(p.size())) {
      p.clear();
      return false;
    }
    return true;
  }

  int operator[](const int i) const {
    assert(init);

    return p[i];
  }
};
