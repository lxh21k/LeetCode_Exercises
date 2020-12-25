#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int> s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int numOfChildren = g.size(), numOfCookie = s.size();
        int count = 0;
        for (int i = 0, j = 0; i < numOfChildren && j < numOfCookie; ++i, ++j) {
            while (j < numOfCookie && s[j] < g[i]) { //这里j<numOfCookie 的判断必须先于s[j] < g[i],否则会出现数组访问越界
                ++j;
            }
            if(j < numOfCookie) ++count;
        }
        return count;
    }
};

