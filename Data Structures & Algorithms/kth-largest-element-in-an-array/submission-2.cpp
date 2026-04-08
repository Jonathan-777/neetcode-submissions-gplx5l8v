class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>> p_q;
        for(auto& x: nums){
            p_q.push(x);

        }
        
        while(k > 1){
            p_q.pop();
            k--;
        }
        return p_q.top();
    }
};
