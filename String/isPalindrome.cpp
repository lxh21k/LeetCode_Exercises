#include <string>

using namespace std;

class Solution{
    public: 
        bool isPalindrome(string s) {
            string sgood;
            for(char ch: s) {
                if(isalnum(ch)) sgood += tolower(ch);
            }
            string sgood_rev(sgood.rbegin(), sgood.rend());
            return sgood_rev == sgood;
        }
};

class Solution1{
    public:
        bool isPalindrome1(string s) {
            int left = 0;
            int right = s.size() - 1;
            while(left < right) {
                while(left < right && !isalnum(s[left])) ++left;
                while(left < right && !isalnum(s[right])) --right;
                if (left < right) {
                    if (tolower(s[left]) != tolower(s[right])) {
                        return false;
                    }
                    ++left;
                    --right;
                }
            }
            return true;
        }
};

