#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
    public:
        string longestCommonPrefix(vector<string>& strs) {
            if(!strs.size()) return "";
            string prefix = strs[0];
            for(int i = 0; i < strs.size(); ++i){
                prefix = longestCommonPrefix(prefix, strs[i]);
                if(!prefix.size()) break;
            }
            return prefix;
        }

        string longestCommonPrefix(const string& str1, const string& str2) {
            int index = 0;
            while( index < min(str1.size(), str2.size()) && str1[index] == str2[index]) {
                ++index;
            }
            return str1.substr(0, index);
        }
};

class Solution1{
    public:
        string longestCommonPrefix1(vector<string>& strs) {
            if(!strs.size()) return "";
            int length = strs[0].size();
            int count = strs.size();
            for(int i = 0; i<length; ++i){
                char c = strs[0][i];
                for(int j = 1; j<count; ++j){
                    if(i == strs[j].size() || strs[j][i] != c) {
                        return strs[0].substr(0, i);
                    }
                }
            }
            return strs[0];
        }
};

class Solution2 {
    public: 
        string longestCommonPrefix2(vector<string>& strs) {
            if(!strs.size()) return "";
            int minLength = min_element(strs.begin(), strs.end(), [](const string& s, const string& t) {
                    return s.size() < t.size();
                    })->size();
            int low = 0, high = minLength;
            while(low < high) {
                int mid = (high - low + 1)/2 + low;
                if(isCommonPrefix(strs, mid)) {
                    low = mid;
                }
                else{
                    high = mid - 1;
                }
            }
            return strs[0].substr(0, low);
}
bool isCommonPrefix(const vector<string>& strs, int length) {
    string str0 = strs[0].substr(0, length);
    int count = strs.size();
    for (int i = 1; i < count; ++i) {
        string str = strs[i];
        for (int j = 0; j < length; ++j) {
            if (str0[j] != str[j]) return false;
        }
    }
    return true;
}
};
