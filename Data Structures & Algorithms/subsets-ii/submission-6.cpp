class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        subsetsWithDup_helper(nums,{}, 0);
        // we can cheese it by just cleaning arr here or using a set in helper function
        return ans;
    }

    void subsetsWithDup_helper(vector<int>& nums, vector<int> working_arr, int index ){
        if(index >= nums.size()){
            ans.push_back(working_arr);
            return;
        }


        
        working_arr.push_back(nums[index]);

        subsetsWithDup_helper(nums, working_arr, index+1);
        working_arr.pop_back();


        // subsetsWithDup_helper(nums,working_arr,index+1);
        // clear dup?

        while(index + 1 < nums.size() && nums[index] == nums[index + 1]){
            index++;
        }

        subsetsWithDup_helper(nums,working_arr,index+1);
        
        return;
        
    }

};
