class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans; 
        vector<int> working_arr;
        combinationSum_helper(nums, ans, working_arr, target, 0, 0);
        return ans;
    }

    
    void combinationSum_helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& working_arr, const int& target, int sum, int start_index) {
        if(sum > target){
            return;
        }
        if(sum == target){
            
            ans.push_back(working_arr); 
            return;
        }
        
       
        for(int i = start_index; i < nums.size(); i++){
            sum += nums[i];
            working_arr.push_back(nums[i]);
            
        
            // We can reuse the current number, but we can't use numbers before 'i'   -- this is the key
            combinationSum_helper(nums, ans, working_arr, target, sum, i);
            
            working_arr.pop_back();
            sum -= nums[i];
        }
    }
};