class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> forward(nums.size(),1);
        vector<int> backwards(nums.size(),1);
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++){
            if(i > 0){
                forward[i] =  forward[i-1] * nums[i] ;
            }else{
                forward[i] = forward[i] * nums[i];
            }
            
        }

        for(int i = nums.size()-1 ; i >= 0; i--){
            if(i < nums.size()-1){
                backwards[i] = nums[i] * backwards[i+1];

            }else{
                backwards[i] = backwards[i] * nums[i];
            }

        }

        for(int i = 0; i < nums.size(); i++){
            if(i == 0){
                ans.push_back(backwards[i+1]);
            }else if(i == nums.size()-1){
                ans.push_back(forward[i-1]);
            }else{
               
                ans.push_back(backwards[i+1] * forward[i-1]);
            }
        }
        return ans;
    }
};
