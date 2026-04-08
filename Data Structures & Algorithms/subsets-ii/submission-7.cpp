class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        subsetsWithDup_helper(*this,nums,{}, 0);
        return ans;
    }

    friend void subsetsWithDup_helper(Solution& var, vector<int>& nums, vector<int> working_arr, int index );

};


void subsetsWithDup_helper(Solution& var, vector<int>& nums, vector<int> working_arr, int index ){
        if(index == nums.size()){
            var.ans.push_back(working_arr);
            return;
        }
        working_arr.push_back(nums[index]);

        subsetsWithDup_helper(var,nums, working_arr, index+1);
        working_arr.pop_back();


        // subsetsWithDup_helper(nums,working_arr,index+1);
        // clear dup?

        while(index + 1 < nums.size() && nums[index] == nums[index + 1]){// must use +1 because -1 would skip items ahead that are not dup
            index++;
        }

        subsetsWithDup_helper(var,nums,working_arr,index+1);
        
        return;
        
    }
