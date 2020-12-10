#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
        int maxSubArray(vector<int>& nums){
            int maxRes = nums[0];
            int pre = 0;
            for(const auto &e: nums){
                pre = max(e, pre+e);
                maxRes = max(maxRes, pre);
            }
            return maxRes;
        }
};
