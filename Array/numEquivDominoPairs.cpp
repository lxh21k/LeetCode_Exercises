#include <vector>

using namespace std;

class Solution {
public: 
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> list(100);
        int res = 0;
        for (auto pair : dominoes) {
            int val = pair[0] < pair[1] ? pair[0] * 10 + pair[1] : pair[1] * 10 + pair[0];
            res += list[val];
            ++list[val];
        }
        return res;
    }
};
