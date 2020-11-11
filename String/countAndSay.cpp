#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        string countAndSay(int n) {
            if(n == 1) return "1";

            string pre = countAndSay(n - 1);
            string cur = "";

            int fastIndex = 0, slowIndex = 0;
            while (fastIndex < pre.size()) {
                while(fastIndex < pre.size() && pre[fastIndex] == pre[slowIndex]) ++fastIndex; // 对于string而言，pre[pre.size()+1]指向"\0"，不越界
                cur += (to_string(fastIndex-slowIndex) + pre[slowIndex]);
                slowIndex = fastIndex;
            }
            return cur;
        }
};
