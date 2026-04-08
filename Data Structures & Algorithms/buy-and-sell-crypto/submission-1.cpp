class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit =0;
        int minNum = INT_MAX;

        for(int i = 0 ; i < prices.size(); i ++){
            minNum = min(minNum, prices[i]);
            maxProfit = max( maxProfit, prices[i] - minNum);
             
        }
        return maxProfit;
    }
};
