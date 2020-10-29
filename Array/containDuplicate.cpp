# include <iostream>
//# include <vector>
//# include <unordered_map>
# include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
            bool containsDuplicate(vector<int>& nums) {
                if (nums.size() == 0) return false; //防止输入为空数组时越界
                sort(nums.begin(), nums.end());
                for (int i = 0; i < nums.size()-1; i++){
                    if (nums[i] == nums[i+1]) return true;
                }
                return false;
            }

};
