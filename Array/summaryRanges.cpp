#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int low = 0;
        for(int i = 1; i <= nums.size(); ++i) {
            if (i == nums.size() || nums[i] != nums[i-1] + 1) {
                result.push_back(to_string(nums[low]) + (low == i ? "" : "->" + to_string(nums[i - 1])));
                low = i;
            }
        }
        return result;
    }
};
