#pragma once

/**
 * @brief Merge Sort Tree
 */
template <class T> class MergeSortTree {
  private:
    int n;
    vector<vector<T>> v, s;

    void update(int i) {
        v[i].clear();
        v[i].reserve(v[i << 1].size() + v[(i << 1) | 1].size());

        merge(v[i << 1].begin(), v[i << 1].end(), v[(i << 1) | 1].begin(),
              v[(i << 1) | 1].end(), back_inserter(v[i]));

        s[i] = vector<T>(v[i].size() + 1);
        for (int j = 0; j < int(v[i].size()); j++) {
            s[i][j + 1] = s[i][j] + v[i][j];
        }
    }

  public:
    MergeSortTree(const vector<T>& _v, const T& inf) {
        n = 1;
        while (n < int(_v.size())) {
            n <<= 1;
        }

        v = vector<vector<T>>(n * 2);
        s = vector<vector<T>>(n * 2);

        for (int i = 0; i < n; i++) {
            if (i < int(_v.size())) {
                v[n + i] = vector<T>({_v[i]});
                s[n + i] = vector<T>({T(0), _v[i]});
            } else {
                v[n + i] = vector<T>({inf});
                s[n + i] = vector<T>({T(0), inf});
            }
        }

        for (int i = n - 1; i >= 1; i--) {
            update(i);
        }
    }

    /**
     * @brief [l, r)に含まれるa以下の数の総和
     */
    T sum(int l, int r, const T& a) const {
        l += n;
        r += n;
        T res = 0;
        while (l < r) {
            if (l & 1) {
                int t = upper_bound(v[l].begin(), v[l].end(), a) - v[l].begin();
                res += s[l][t];
                l++;
            }
            if (r & 1) {
                r--;
                int t = upper_bound(v[r].begin(), v[r].end(), a) - v[r].begin();
                res += s[r][t];
            }
            l >>= 1;
            r >>= 1;
        }

        return res;
    }

    /**
     * @brief [l, r)に含まれるa以下の数の個数
     */
    int count(int l, int r, const T& a) const {
        l += n;
        r += n;

        int res = 0;
        while (l < r) {
            if (l & 1) {
                int t = upper_bound(v[l].begin(), v[l].end(), a) - v[l].begin();
                res += t;
                l++;
            }
            if (r & 1) {
                r--;
                int t = upper_bound(v[r].begin(), v[r].end(), a) - v[r].begin();
                res += t;
            }
            l >>= 1;
            r >>= 1;
        }

        return res;
    }
};
