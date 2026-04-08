class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0; 
        int min_history = INT_MAX;
        for(int i = 0 ; i < prices.size(); i++){
            min_history = min(min_history, prices[i]);
            ans = max(ans, prices[i] - min_history);
        }
        return ans;
    }
};
