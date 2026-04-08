class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        
        // OPTIMIZATION 1: Reserve capacity to prevent vector reallocations.
        // In the worst case (all unique elements), size is 2^N.
        res.reserve(1 << nums.size()); 
        res.push_back({});
        
        int prevIdx = 0;
        int idx = 0;

        for (int i = 0; i < nums.size(); i++) {
            idx = (i >= 1 && nums[i] == nums[i - 1]) ? prevIdx : 0;
            prevIdx = res.size();
            
            for (int j = idx; j < prevIdx; j++) {
                vector<int> tmp = res[j]; 
                tmp.push_back(nums[i]);
                
                // OPTIMIZATION 2: std::move transfers the memory of tmp 
                // directly into res, saving a deep copy operation.
                res.push_back(std::move(tmp)); 
            }
        }

        return res;
    }
};