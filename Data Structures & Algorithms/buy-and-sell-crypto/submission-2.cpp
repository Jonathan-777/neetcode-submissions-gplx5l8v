class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minNum = INT_MAX;
        
        for(auto x : prices){
            minNum = min(minNum, x);
            profit = max(profit, x - minNum);
        }
        return profit;
    }
};
