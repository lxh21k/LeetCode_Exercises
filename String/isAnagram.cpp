#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution{
    public:
        bool isAnagram(string s, string t) {
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            return s == t;
        }
};

class Solution1{
    public:
        bool isAnagram1(string s, string t) {
            if(s.size() != t.size()) return false;
            unordered_map<int, int> map;
            for(auto c: s) map[c]++;
            for(auto c: t) map[c]--;
            for(auto v: map) {
                if(v.second != 0) return false;
            }
            return true;
        }
};
