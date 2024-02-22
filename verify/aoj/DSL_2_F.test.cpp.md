---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/ordered_map_and_range_query.hpp
    title: data_structure/ordered_map_and_range_query.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
  bundledCode: "#line 1 \"verify/aoj/DSL_2_F.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F\"\
    \n\n// #define _GLIBCXX_DEBUG\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \n#line 2 \"data_structure/ordered_map_and_range_query.hpp\"\n\ntemplate<\n\t\
    class K, bool (*compare)(K,K),\n\tclass S, S (*op)(S,S), S (*e)(),\n\tclass F,\
    \ S (*mapping)(F,S), F (*composition)(F,F), F (*id)()\n\t>\nclass OrderedMapAndRangeQuery{\n\
    \tprivate:\n\t\tclass Node{\n\t\t\tpublic:\n\t\t\t\tint size;\n\t\t\t\tNode* left,\
    \ *right;\n\t\t\t\tK key;\n\t\t\t\tS value, sum;\n\t\t\t\tF lazy;\n\n\t\t\t\t\
    Node(K _key): Node(_key, e()) {}\n\t\t\t\tNode(K _key, S _value): Node(_key, _value,\
    \ id()) {}\n\t\t\t\tNode(K _key, S _value, F _lazy):\n\t\t\t\t\tsize(1), left(nullptr),\
    \ right(nullptr),\n\t\t\t\t\tkey(_key), value(_value), sum(_value), lazy(_lazy){}\n\
    \t\t};\n\n\t\tNode* root;\n\n\t\tint size(Node* node){\n\t\t\tif(node==nullptr)\
    \ return 0;\n\t\t\treturn node->size;\n\t\t}\n\n\t\tS value(Node* node){\n\t\t\
    \tif(node==nullptr) return e();\n\t\t\treturn node->value;\n\t\t}\n\n\t\tS sum(Node*\
    \ node){\n\t\t\tif(node==nullptr) return e();\n\t\t\treturn node->sum;\n\t\t}\n\
    \n\t\tF lazy(Node* node){\n\t\t\tif(node==nullptr) return id();\n\t\t\treturn\
    \ node->lazy;\n\t\t}\n\n\t\tvoid propagate(Node* node, F f){\n\t\t\tif(node==nullptr)\
    \ return;\n\t\t\tnode->value = mapping(f, value(node));\n\t\t\tnode->sum = mapping(f,\
    \ sum(node));\n\t\t\tnode->lazy = composition(f, lazy(node));\n\t\t}\n\n\t\tvoid\
    \ push(Node* node){\n\t\t\tif(node==nullptr) return;\n\t\t\tif(lazy(node)!=id()){\n\
    \t\t\t\tpropagate(node->left, lazy(node));\n\t\t\t\tpropagate(node->right, lazy(node));\n\
    \t\t\t\tnode->lazy = id();\n\t\t\t}\n\t\t}\n\n\t\tvoid update(Node* node){\n\t\
    \t\tpush(node);\n\t\t\tif(node==nullptr) return;\n\t\t\tnode->sum = op(op(sum(node->left),\
    \ value(node)), sum(node->right));\n\t\t\tnode->size = size(node->left) + 1 +\
    \ size(node->right);\n\t\t}\n\n\t\tint lower_bound(Node* node, K k){\n\t\t\tpush(node);\n\
    \t\t\tif(node==nullptr) return 0;\n\t\t\tif(compare(node->key, k)){\n\t\t\t\t\
    return size(node->left) + lower_bound(node->right, k) + 1;\n\t\t\t}\n\t\t\treturn\
    \ lower_bound(node->left, k);\n\t\t}\n\n\t\tint upper_bound(Node* node, K k){\n\
    \t\t\tpush(node);\n\t\t\tif(node==nullptr) return 0;\n\t\t\tif(compare(k, node->key)){\n\
    \t\t\t\treturn upper_bound(node->left, k);\n\t\t\t}\n\t\t\treturn size(node->left)\
    \ + upper_bound(node->right, k) + 1;\n\t\t}\n\n\t\tpair<K, S> get(Node* node,\
    \ int i){\n\t\t\tpush(node);\n\t\t\tassert(node!=nullptr);\n\t\t\tif(i==size(node->left))\
    \ return make_pair(node->key, value(node));\n\t\t\tif(i<size(node->left)) return\
    \ get(node->left, i);\n\t\t\treturn get(node->right, i - size(node->left) - 1);\n\
    \t\t}\n\n\t\tunsigned xor128(){\n\t\t\tstatic unsigned x = 123'456'789, y = 362'436'069,\
    \ z = 521'288'629, w = 88'675'123;\n\t\t\tunsigned t = x^(x<<11);\n\t\t\tx = y,\
    \ y = z, z = w, w = (w^(w>>19))^(t^(t>>8));\n\t\t\treturn w;\n\t\t}\n\n\t\tNode*\
    \ merge(Node* l, Node* r){\n\t\t\tpush(l), push(r);\n\t\t\tif(l==nullptr) return\
    \ r;\n\t\t\tif(r==nullptr) return l;\n\t\t\tif(xor128() % (size(l)+size(r)) <\
    \ unsigned(size(l))){\n\t\t\t\tl->right = merge(l->right, r);\n\t\t\t\tupdate(l);\n\
    \t\t\t\treturn l;\n\t\t\t}\n\t\t\tr->left = merge(l, r->left);\n\t\t\tupdate(r);\n\
    \t\t\treturn r;\n\t\t}\n\n\t\tpair<Node*, Node*> split(Node* node, int i){\n\t\
    \t\tpush(node);\n\t\t\tif(node==nullptr) return make_pair(nullptr,nullptr);\n\t\
    \t\tif(i<=size(node->left)){\n\t\t\t\tpair<Node*, Node*> s = split(node->left,\
    \ i);\n\t\t\t\tnode->left = s.second;\n\t\t\t\tupdate(node);\n\t\t\t\treturn make_pair(s.first,\
    \ node);\n\t\t\t}\n\t\t\tpair<Node*, Node*> s = split(node->right, i - size(node->left)\
    \ - 1);\n\t\t\tnode->right = s.first;\n\t\t\tupdate(node);\n\t\t\treturn make_pair(node,\
    \ s.second);\n\t\t}\n\n\tpublic:\n\t\tOrderedMapAndRangeQuery():root(nullptr){}\n\
    \n\t\tint size(){\n\t\t\treturn size(root);\n\t\t}\n\n\t\tint lower_bound(K k){\n\
    \t\t\treturn lower_bound(root, k);\n\t\t}\n\n\t\tint upper_bound(K k){\n\t\t\t\
    return upper_bound(root, k);\n\t\t}\n\n\t\tbool count(K k){\n\t\t\treturn upper_bound(k)!=lower_bound(k);\n\
    \t\t}\n\n\t\tpair<K, S> get(int i){\n\t\t\treturn get(root, i);\n\t\t}\n\n\t\t\
    void erase(K k){\n\t\t\tif(!count(k)) return;\n\t\t\tpair<Node*, Node*> s = split(root,\
    \ lower_bound(k));\n\t\t\tpair<Node*, Node*> t = split(s.second, 1);\n\t\t\tdelete\
    \ t.first;\n\t\t\troot = merge(s.first, t.second);\n\t\t}\n\n\t\tvoid insert(K\
    \ k, S v){\n\t\t\tif(count(k)) erase(k);\n\t\t\tpair<Node*, Node*> s = split(root,\
    \ lower_bound(k));\n\t\t\troot = merge(merge(s.first, new Node(k,v)), s.second);\n\
    \t\t}\n\n\t\tS prod(int a, int b){\n\t\t\tpair<Node*, Node*> s = split(root, a);\n\
    \t\t\tpair<Node*, Node*> t = split(s.second, b-a);\n\t\t\tS res = sum(t.first);\n\
    \t\t\troot = merge(s.first, merge(t.first, t.second));\n\t\t\treturn res;\n\t\t\
    }\n\n\t\tvoid apply(int a, int b, F f){\n\t\t\tpair<Node*, Node*> s = split(root,\
    \ a);\n\t\t\tpair<Node*, Node*> t = split(s.second, b-a);\n\t\t\tpropagate(t.first,\
    \ f);\n\t\t\troot = merge(s.first, merge(t.first, t.second));\n\t\t}\n};\n#line\
    \ 8 \"verify/aoj/DSL_2_F.test.cpp\"\n\nusing ll = long long;\nconstexpr ll INF32\
    \ = (1LL<<31)-1;\nconstexpr ll INF64 = 1LL<<60;\n\nusing K = ll;\nbool compare(K\
    \ a, K b){\n    return a < b;\n}\n\nusing S = ll;\nS op(S a, S b){\n    return\
    \ min(a, b);\n}\nS e(){\n    return INF32;\n}\n\nusing F = ll;\nconstexpr F ID\
    \ = INF64;\nS mapping(F f, S a){\n    if(f==ID) return a;\n    return f;\n}\n\
    F composition(F f, F g){\n    if(f==ID) return g;\n    return f;\n}\nF id(){\n\
    \    return ID;\n}\n\nint main(){\n    int N, Q;\n    cin >> N >> Q;\n\n    OrderedMapAndRangeQuery<K,\
    \ compare, S, op, e, F, mapping, composition, id> rbst;\n    rbst.insert(-INF64,\
    \ e());\n    rbst.insert(INF64, e());\n\n    for(;Q--;){\n        int t;\n   \
    \     cin >> t;\n        if(t==0){\n            ll l, r, x;\n            cin >>\
    \ l >> r >> x;\n            r++;\n            if(!rbst.count(l)){\n          \
    \      rbst.insert(l, rbst.get(rbst.lower_bound(l)-1).second);\n            }\n\
    \            if(!rbst.count(r)){\n                rbst.insert(r, rbst.get(rbst.lower_bound(r)-1).second);\n\
    \            }\n            rbst.apply(rbst.lower_bound(l), rbst.lower_bound(r),\
    \ x);\n        }\n        else{\n            ll l, r;\n            cin >> l >>\
    \ r;\n            r++;\n            cout << rbst.prod(rbst.upper_bound(l)-1, rbst.lower_bound(r))\
    \ << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F\"\
    \n\n// #define _GLIBCXX_DEBUG\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \n#include \"../../data_structure/ordered_map_and_range_query.hpp\"\n\nusing ll\
    \ = long long;\nconstexpr ll INF32 = (1LL<<31)-1;\nconstexpr ll INF64 = 1LL<<60;\n\
    \nusing K = ll;\nbool compare(K a, K b){\n    return a < b;\n}\n\nusing S = ll;\n\
    S op(S a, S b){\n    return min(a, b);\n}\nS e(){\n    return INF32;\n}\n\nusing\
    \ F = ll;\nconstexpr F ID = INF64;\nS mapping(F f, S a){\n    if(f==ID) return\
    \ a;\n    return f;\n}\nF composition(F f, F g){\n    if(f==ID) return g;\n  \
    \  return f;\n}\nF id(){\n    return ID;\n}\n\nint main(){\n    int N, Q;\n  \
    \  cin >> N >> Q;\n\n    OrderedMapAndRangeQuery<K, compare, S, op, e, F, mapping,\
    \ composition, id> rbst;\n    rbst.insert(-INF64, e());\n    rbst.insert(INF64,\
    \ e());\n\n    for(;Q--;){\n        int t;\n        cin >> t;\n        if(t==0){\n\
    \            ll l, r, x;\n            cin >> l >> r >> x;\n            r++;\n\
    \            if(!rbst.count(l)){\n                rbst.insert(l, rbst.get(rbst.lower_bound(l)-1).second);\n\
    \            }\n            if(!rbst.count(r)){\n                rbst.insert(r,\
    \ rbst.get(rbst.lower_bound(r)-1).second);\n            }\n            rbst.apply(rbst.lower_bound(l),\
    \ rbst.lower_bound(r), x);\n        }\n        else{\n            ll l, r;\n \
    \           cin >> l >> r;\n            r++;\n            cout << rbst.prod(rbst.upper_bound(l)-1,\
    \ rbst.lower_bound(r)) << endl;\n        }\n    }\n}\n"
  dependsOn:
  - data_structure/ordered_map_and_range_query.hpp
  isVerificationFile: true
  path: verify/aoj/DSL_2_F.test.cpp
  requiredBy: []
  timestamp: '2024-02-22 10:09:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/DSL_2_F.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/DSL_2_F.test.cpp
- /verify/verify/aoj/DSL_2_F.test.cpp.html
title: verify/aoj/DSL_2_F.test.cpp
---
