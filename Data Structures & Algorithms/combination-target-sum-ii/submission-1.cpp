class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        combinationSum2_helper(nums,{}, target, 0, 0);
        return ans;

    }
    void combinationSum2_helper(vector<int>& nums, vector<int> working_arr,const int& target , int curr_sum, int index){
        if(curr_sum == target){
            ans.push_back(working_arr);
            return;
        }

        for(int i = index; i < nums.size(); i++){
            if(i > index && nums[i] == nums[i-1])continue;

            if(target < curr_sum + nums[i])break;

            working_arr.push_back(nums[i]);
            combinationSum2_helper( nums, working_arr, target, curr_sum + nums[i], i+1);
            working_arr.pop_back();

        }
    }
};
