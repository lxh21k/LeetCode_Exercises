#include<iostream>
#include<vector>
#include<random>

using namespace std;

class Solution {
    public:
        Solution(vector<int>& nums) {
            this->data = nums;
        }

        vector<int> reset(){
            return data;
        }

        vector<int> shuffle() {
            vector<int> shuffled(data.begin(), data.end());
            for(int i = 0; i < data.size(); ++i) {
                swap(shuffled[i], shuffled[rand() % (i+1)]);
            }
            return shuffled;
        }

    private:
        vector<int> data;
};
