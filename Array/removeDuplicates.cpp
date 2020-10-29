#include <iostream>
using namespace std;

int main(){
    cout << "Hello" << endl;
    return 0;
}

class Solution{
public:
    int removeDuplicates(vector<int>& nums){
    if (nums.size() == 0) return 0;
    int fastIndex, slowIndex = 0
    for (fastIndex = 0; fastIndex < (nums.size()-1); fastIndex++){
        if(nums[fastIndex] != nums[fastIndex+1]){
            nums[++slowIndex] = nums[fastIndex + 1];
        }
    }
    return slowIndex + 1;
};


