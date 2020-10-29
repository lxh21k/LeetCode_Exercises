#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
        int maxProfit(vector<int>& prices){
            int i = 0;
            int valley = prices[0];
            int peak = prices[0];
            int maxprofit = 0;
            while (i < prices.size() - 1){
                while (i < prices.size() - 1 && prices[i] >= prices[i+1])
                    i++;
                valley = prices[i];
                while (i < prices.size() - 1 && prices[i] < prices[i+1])
                    i++;
                peak = prices[i];
                maxprofit += peak - valley;
            }
            return maxprofit;
        }
};

class Solution1{
    public:
        int maxProfit1(vector<int>& prices){
            int maxprofit = 0;
            for (int i = 0; i < prices.size() - 1; i++){
                if(prices[i] < prices[i+1])
                    maxprofit += prices[i+1] - prices[i];
            }
            return maxprofit;
        }
};

int main(){
    vector<int> v = {7,1,5,3,6,4};
    Solution1 solu;
    int result = solu.maxProfit1(v); 
    cout << result <<endl;
    return result;
}


