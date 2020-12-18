#include<iostream>

using namespace std;

class Solution {
    public:
    bool isPrime(int x) {
        for (int i = 2; i*i <= x; ++i) {
            if (x % i == 0) return false;
        }
        return true;
    }
    int countPrimes(int n) {
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime(i)) ++ans;
        }
        return ans;
    }
};
