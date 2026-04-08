class Solution {
public:
    vector<vector<int>> res;
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        dfs(0, 0, target, {}, nums); 
        return res;
    }

    
    void dfs(int i, int total, int target, vector<int> cur, vector<int>& nums) {
        if (total == target) {
            res.push_back(cur);
            return;
        }

        for (int j = i; j < nums.size(); j++) {  // j = i helps us avoid repetition of combinations, adhearing strictly to multisets
            if (total + nums[j] > target) {// for every summation less than or equal to target, recurse
                return;
            }
            cur.push_back(nums[j]);
            //recurse
            dfs(j, total + nums[j], target, cur, nums);
            cur.pop_back();// remove items that overshoot
        }
    }
};