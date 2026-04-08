class Solution {
public:
        vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        combinationSum_helper(nums,{},0,0,target);
        return ans;
        
    }

    void combinationSum_helper(vector<int>& nums, vector<int> candidates,int index, int curr_sum, int target){// must be more efficent thatn using a set
        if(curr_sum == target){
            ans.push_back(candidates);
            return;
        }
        if(curr_sum > target){
            return;
        }

        for(int i = index ; i < nums.size(); i++){
            
            if(curr_sum + nums[i] > target)break;
            candidates.push_back(nums[i]);

            combinationSum_helper(nums, candidates, i, curr_sum + nums[i], target);
            candidates.pop_back();
            
            
        }

    }


};
