#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            for (int i = digits.size()-1; i>=0; i--)
            {
                digits[i]++;
                if (digits[i] >= 10) digits[i]=0;
                else return digits;
            }
            digits.insert(digits.begin(), 1);
            return digits;
        }
};
