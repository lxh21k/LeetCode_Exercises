#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int r0 = nums.size();
        int c0 = nums[0].size();
        if (r0*c0 != r*c) {
            return nums;
        }

        vector<vector<int>> ans(r, vector<int>(c));
        for (int i = 0; i < r*c; ++i) {
            ans[i/c][i%c] = nums[i/c0][i%c0];
        }
        return ans;
    }
};
