class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        if(nums.size() == 1 && nums[0] != target){
            return {};
        }
        set<vector<int>> ans;
        combinationSum_helper(nums,ans,{},target,0);
         vector<vector<int>> result(ans.begin(),ans.end());
         return result;
        
    }

    void combinationSum_helper(vector<int>& nums, set<vector<int>>& ans, vector<int> working_arr, const int& target, int sum ){
        if(sum > target){
            return;
        }
        if(sum == target){
            sort(working_arr.begin(), working_arr.end());
            ans.insert(working_arr);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            working_arr.push_back(nums[i]);
            combinationSum_helper(nums,ans,working_arr,target,sum);
            working_arr.pop_back();
            sum -= nums[i];

        }
    }
};
