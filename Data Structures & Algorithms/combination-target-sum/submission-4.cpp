class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        combinationSum_helper(nums, {}, 0,target, 0);
        return ans;
    }

    void combinationSum_helper(vector<int>& nums, vector<int> working_arr, int curr_sum, int target, int index){
        if(target == curr_sum){
            ans.push_back(working_arr);
        }

        for( int  i = index; i < nums.size(); i++){
            if(target < curr_sum + nums[i]){
                break;
            }
            working_arr.push_back(nums[i]);
            combinationSum_helper( nums, working_arr, curr_sum + nums[i], target, i);
            working_arr.pop_back();
        }
    }
};
