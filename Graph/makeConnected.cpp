#include <vector>

using namespace std;

class UnionFind {
private:
    vector<int> f, sz;
public:
    int setCount;
    UnionFind(int n): f(n), sz(n) {
        for (int i = 0; i < n; i++) {
            f[i] = i;
            sz[i] = 1;
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
        sz[fy] += sz[fx];
        --setCount;
    }

    int size(int x) {
        return sz[find(x)];
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }

        UnionFind uf(n);
        for (const auto& connection : connections) {
            uf.merge(connection[0], connection[1]);
        }
        return uf.setCount - 1;
    }
};

