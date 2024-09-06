#pragma once

template <class T, class C = less<T>>
class Compress {
 private:
  bool init;
  vector<T> vec;

 public:
  Compress() : Compress(vector<T>()) {}
  Compress(const vector<T>& _vec) : init(false), vec(_vec) {}

  void push(const T x) {
    assert(!init);

    vec.push_back(x);
  }

  void build() {
    assert(!init);
    init = true;

    sort(vec.begin(), vec.end(), C());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
  }

  size_t size() const {
    assert(init);

    return vec.size();
  }

  T nth(const int i) const {
    assert(init);

    assert(0 <= i && i < int(vec.size()));
    return vec[i];
  }

  int get(const T x) const {
    assert(init);

    int ng = -1, ok = int(vec.size()) - 1;
    while (1 < ok - ng) {
      int mid = (ok + ng) / 2;
      if (!C()(vec[mid], x))
        ok = mid;
      else
        ng = mid;
    }
    return ok;
  }

  bool contains(const T x) const {
    assert(init);

    return nth(get(x)) == x;
  }
};
