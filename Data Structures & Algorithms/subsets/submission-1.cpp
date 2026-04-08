class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        subsets_helper(nums,{},0);
        return ans;
    }

    void subsets_helper(vector<int>& nums, vector<int> working_arr, int curr_size ){
        if(curr_size >= nums.size()){
            ans.push_back(working_arr);
            return;
        }
        working_arr.push_back(nums[curr_size]);
        subsets_helper(nums, working_arr, curr_size + 1);
        working_arr.pop_back();
        subsets_helper(nums, working_arr, curr_size + 1);
    }
};
