#include <string>
#include <bits/stdc++.h>

using namespace std;
// 使用常规做法

class Solution{
    public:
        int myAtoi(string s) {
            int i = 0;
            int result = 0;
            int flag = 1;
            while(s[i] == ' ') ++i;
            if (s[i] == '-') flag = -1;
            if (s[i] == '+' || s[i] == '-') ++i;
            while (i<s.size() && isdigit(s[i])) {
               if (result < ((flag>0?(INT_MIN+1): INT_MIN)+(s[i]-'0'))/10) {
                   return flag > 0? INT_MAX : INT_MIN;
               }
               result = 10*result - (s[i]-'0');
               ++i;
            }
            return flag>0?-result:result;
        }
};

