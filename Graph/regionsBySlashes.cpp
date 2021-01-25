#include <vector>

using namespace std;

class UnionFind {
private:
    vector<int> f;
public:
    int setCount;
    UnionFind(int n): f(n) {
        for (int i = 0; i < n; ++i) {
            f[i] = i;
        }
        setCount = n;
    }

    int find(int x) {
        if (f[x] == x) {
            return x;
        }
        int newf = find(f[x]);
        f[x] = newf;
        return f[x];
    }

    void merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) {
            return;
        }
        f[fx] = fy;
        --setCount;
    }
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        UnionFind uf(n * n * 4);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int idx  = i * n + j;
                if (i < n - 1) {
                    uf.merge(idx * 4 + 2, (idx + n) * 4);
                }
                if (j < n - 1) {
                    uf.merge(idx * 4 + 1, (idx + 1) * 4 + 3);
                }
                if (grid[i][j] == '/') {
                    uf.merge(idx * 4, idx * 4 + 3);
                    uf.merge(idx * 4 + 1, idx * 4 + 2);
                }
                else if (grid[i][j] == '\\') {
                    uf.merge(idx * 4, idx * 4 + 1);
                    uf.merge(idx * 4 + 2, idx * 4 + 3);
                }
                else {
                    uf.merge(idx * 4, idx * 4 + 1);
                    uf.merge(idx * 4 + 1, idx * 4 + 2);
                    uf.merge(idx * 4 + 2, idx * 4 + 3);
                }
            }
        }

        return uf.setCount;
    }
};

