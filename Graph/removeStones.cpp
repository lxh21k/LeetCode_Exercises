#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int Find(vector<int>& parent, int index) {
        if (parent[index] != index) {
            parent[index] = Find(parent, parent[index]);
        }
        return parent[index];
    }

    void Union(vector<int>& parent, int index1, int index2) {
        parent[Find(parent, index1)] = Find(parent, index2);
    }

    int removeStones(vector<vector<int>>& stones) {
        int stonesCount = stones.size();
        vector<int> parent(20005);
        for (int i = 0; i < 20005; ++i) {
            parent[i] = i;
        }
        for (auto& stone: stones) {
            int x = stone[0], y = stone[1];
            Union(parent, x, y + 10000);
        }
        unordered_map<int, bool> umap;
        for (auto& stone: stones) {
            umap[Find(parent, stone[0])] = true;
            umap[Find(parent, stone[1] + 10000)] = true;
        }
        return stonesCount - umap.size();
    }
};
