#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution{
    public:
        int firstUniqChar(string s){
            unordered_map<int, int> map;
            for(auto c : s) map[c]++;
            for(int i = 0; i < s.size(); i++)
                if(map[s[i]] == 1) return i;
            return -1;
        }
};
