class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        vector<int> prefix(nums.size(),1);
        vector<int> suffix(nums.size(),1);
        prefix[0] = nums[0];
        suffix[nums.size() -1] = nums[nums.size() -1];
        

        for(int i = 1 ; i < nums.size(); i++){
            prefix[i] = prefix[i-1] * nums[i];
        }

        for(int i = nums.size() -2; i >= 0; i--){
            suffix[i] = suffix[i+1] * nums[i];
        }

        for(int i = 0; i < nums.size(); i++){
            int temp = 1;
            if(i > 0 ){
                temp = temp * prefix[i-1];
            }
            if(i < nums.size() - 1){
                temp = temp * suffix[i+1];

            }
            ans.push_back(temp);
        }
        return ans;

    }
};
