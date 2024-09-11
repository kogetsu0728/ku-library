#pragma once

/**
 * @brief Ordered Map and Range Query
 */
template <class K,
          bool (*compare)(K, K),
          class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
class OrderedMapAndRangeQuery {
  private:
    class Node {
      public:
        int size;
        Node *left, *right;
        K key;
        S value, sum;
        F lazy;

        Node(K _key) : Node(_key, e()) {}
        Node(K _key, S _value) : Node(_key, _value, id()) {}
        Node(K _key, S _value, F _lazy)
            : size(1),
              left(nullptr),
              right(nullptr),
              key(_key),
              value(_value),
              sum(_value),
              lazy(_lazy) {}
    };

    Node* root;

    int size(Node* node) {
        if (node == nullptr) return 0;
        return node->size;
    }

    S value(Node* node) {
        if (node == nullptr) return e();
        return node->value;
    }

    S sum(Node* node) {
        if (node == nullptr) return e();
        return node->sum;
    }

    F lazy(Node* node) {
        if (node == nullptr) return id();
        return node->lazy;
    }

    void propagate(Node* node, F f) {
        if (node == nullptr) return;
        node->value = mapping(f, value(node));
        node->sum = mapping(f, sum(node));
        node->lazy = composition(f, lazy(node));
    }

    void push(Node* node) {
        if (node == nullptr) return;
        if (lazy(node) != id()) {
            propagate(node->left, lazy(node));
            propagate(node->right, lazy(node));
            node->lazy = id();
        }
    }

    void update(Node* node) {
        push(node);
        if (node == nullptr) return;
        node->sum = op(op(sum(node->left), value(node)), sum(node->right));
        node->size = size(node->left) + 1 + size(node->right);
    }

    int lower_bound(Node* node, K k) {
        push(node);
        if (node == nullptr) return 0;
        if (compare(node->key, k)) {
            return size(node->left) + lower_bound(node->right, k) + 1;
        }
        return lower_bound(node->left, k);
    }

    int upper_bound(Node* node, K k) {
        push(node);
        if (node == nullptr) return 0;
        if (compare(k, node->key)) {
            return upper_bound(node->left, k);
        }
        return size(node->left) + upper_bound(node->right, k) + 1;
    }

    pair<K, S> get(Node* node, int i) {
        push(node);
        assert(node != nullptr);
        if (i == size(node->left)) return make_pair(node->key, value(node));
        if (i < size(node->left)) return get(node->left, i);
        return get(node->right, i - size(node->left) - 1);
    }

    unsigned xor128() {
        static unsigned x = 123'456'789, y = 362'436'069, z = 521'288'629,
                        w = 88'675'123;
        unsigned t = x ^ (x << 11);
        x = y, y = z, z = w, w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
        return w;
    }

    Node* merge(Node* l, Node* r) {
        push(l), push(r);
        if (l == nullptr) return r;
        if (r == nullptr) return l;
        if (xor128() % (size(l) + size(r)) < unsigned(size(l))) {
            l->right = merge(l->right, r);
            update(l);
            return l;
        }
        r->left = merge(l, r->left);
        update(r);
        return r;
    }

    pair<Node*, Node*> split(Node* node, int i) {
        push(node);
        if (node == nullptr) return make_pair(nullptr, nullptr);
        if (i <= size(node->left)) {
            pair<Node*, Node*> s = split(node->left, i);
            node->left = s.second;
            update(node);
            return make_pair(s.first, node);
        }
        pair<Node*, Node*> s = split(node->right, i - size(node->left) - 1);
        node->right = s.first;
        update(node);
        return make_pair(node, s.second);
    }

  public:
    OrderedMapAndRangeQuery() : root(nullptr) {}

    int size() { return size(root); }

    int lower_bound(K k) { return lower_bound(root, k); }

    int upper_bound(K k) { return upper_bound(root, k); }

    bool count(K k) { return upper_bound(k) != lower_bound(k); }

    pair<K, S> get(int i) { return get(root, i); }

    void erase(K k) {
        if (!count(k)) return;
        pair<Node*, Node*> s = split(root, lower_bound(k));
        pair<Node*, Node*> t = split(s.second, 1);
        delete t.first;
        root = merge(s.first, t.second);
    }

    void insert(K k, S v) {
        if (count(k)) erase(k);
        pair<Node*, Node*> s = split(root, lower_bound(k));
        root = merge(merge(s.first, new Node(k, v)), s.second);
    }

    S prod(int a, int b) {
        pair<Node*, Node*> s = split(root, a);
        pair<Node*, Node*> t = split(s.second, b - a);
        S res = sum(t.first);
        root = merge(s.first, merge(t.first, t.second));
        return res;
    }

    void apply(int a, int b, F f) {
        pair<Node*, Node*> s = split(root, a);
        pair<Node*, Node*> t = split(s.second, b - a);
        propagate(t.first, f);
        root = merge(s.first, merge(t.first, t.second));
    }
};
