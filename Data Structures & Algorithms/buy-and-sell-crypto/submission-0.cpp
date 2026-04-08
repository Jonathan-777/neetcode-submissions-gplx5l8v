class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        vector<int> maxElem;
        maxElem.reserve(size);
        int temp = prices[size-1];
        int ans = 0; 

        for(int i = size-1; i >= 0; i--){
            temp = max(temp,prices[i]);
            maxElem[i] = temp;
        }

        for(int i = 0; i < size ; i++){
            int candidate = 0;

            candidate = (maxElem[i] - prices[i]);

            ans = max(ans,candidate);
        }

        return ans;
    }
};
