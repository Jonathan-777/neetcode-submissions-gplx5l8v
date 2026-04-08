class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {
        for(int i = cost.size()-3; i >= 0 ; i--){// start at the end, we will use the last 2 options as a base to build up both possibilities

            cost[i] += min(cost[i+1], cost[i+2]);// whichever is smaller guarantees the right answer

        }
        
        return min(cost[0], cost[1]);// whichever is smaller got the right path
        
    }


};
