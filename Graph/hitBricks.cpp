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

    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int h = grid.size(), w = grid[0].size();

        vector<int> parent(h*w+1);
        for (int i = 0; i < (h*w+1); ++i) {
            parent[i] = i;
            sz[i] = 1;
        }
        vector<vector<int>> status = grid;
        for (int i = 0; i < hits.size(); ++i) {
            status[hits[i][0]][hits[i][1]] = 0;
        }
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (status[i][j] == 1) {
                    if (i == 0) {
                        Union(parent, h * w, i * w + j);
                    }
                    if (i > 0 && status[i - 1][j] ==1) {
                        Union(parent, i * w + j, (i - 1) * w + j);
                    }
                    if (j > 0 && status[i][j - 1] == 1) {
                        Union(parent, i * w + j, i * w + j - 1);
                    }
                }
            }
        }
        const vector<pair<int, int>> directions{{0, 1},{1, 0},{0, -1},{-1, 0}};
        vector<int> ret(hits.size(), 0);
        for (int i = hits.size() - 1; i >=0; --i) {
            int r = hits[i][0], c = hits[i][1];
            if (grid[r][c] == 0) {
                continue;
            }

            if (r == 0) {
                Union(parent, c, h * w);
            }
            for (const auto [dr, dc]: directions) {
                int nr = r + dr, nc = c + dc;

                if (nr >= 0 && nr < h && nc >= 0 && nc < w) {
                    if (status[nr][nc] == 1) {
                        Union(parent, r * w + c, nr * w + nc);
                    }
                }
            }

