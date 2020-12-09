#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution {
    public:
        int maxProfit(vector<int> &prices){
            int maxprofit = 0;
            int minprice = INT_MAX;
            for (int price: prices){
                maxprofit = max(maxprofit, price - minprice);
                minprice = min(minprice, price);
            }
            return maxprofit;
        }
};
