#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int fastIndex, slowIndex = 0;
            for(fastIndex = 0; fastIndex < (nums.size() - 1); fastIndex++)
            {
                    if (nums.size() == 1) break;
                    if (nums[fastIndex] != 0 && nums[slowIndex] == 0)
                    {
                        nums[slowIndex] = nums[fastIndex];
                        nums[fastIndex] = 0;
                        slowIndex++;
                    }
                    else if(nums[fastIndex] == 0 && nums[slowIndex] != 0) slowIndex = fastIndex;
                    else slowIndex++;
            }
        }
};
