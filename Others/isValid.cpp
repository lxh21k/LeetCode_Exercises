#include<iostream>

using namespace std;

class Solution{
public:
	bool isValid(string s) {
		int n = s.size();
		if (n % 2 == 1) {
			return false;
		}

		unorder_map<char, char> pairs = {
			{')', '('},
			{']', '['},
			{'}', '{'}
		};
		stack<char> stk;
		for (char ch: s) {
			if (pairs.count(ch)) {
				if (stk.empty() || stk.top() != pairs[ch]) {
					return false;
				}
				stk.pop();
			}
			else {
				stk.push();
			}
		}
		return stk.empty();
	}
};
