#pragma once

template <class T, class C = less<T>>
class DoubleEndedPriorityQueue : public multiset<T, C> {
 public:
  DoubleEndedPriorityQueue() : multiset<T>() {}

  void push(T val) { this->insert(val); }

  T min() const { return *(this->begin()); }

  T max() const { return *(--(this->end())); }

  void pop_min() { this->erase(this->begin()); }

  void pop_max() { this->erase(--(this->end())); }
};
