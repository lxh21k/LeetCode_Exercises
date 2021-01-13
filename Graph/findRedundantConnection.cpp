#include <iostream>
#include <vector>

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

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int nodesCount = edges.size();
        vector<int> parent(nodesCount+1);
        // 初始化 将每个元素的父节点设为自己
        for (int i = 1; i <= nodesCount; ++i){
            parent[i] = i;
        }
        // 遍历所有的边
        for (auto& edge: edges) {
            // 提取出一条边的两个节点
            int node1 = edge[0], node2 = edge[1];
            // 如果两个之间没有连接（根节点不同），合并
            if (Find(parent, node1) != Find(parent, node2)) {
                Union(parent, node1, node2);
            }
            // 否则这条边即冗余边
            else {
                return edge;
            }
        }
        return vector<int>{};
    }
};
