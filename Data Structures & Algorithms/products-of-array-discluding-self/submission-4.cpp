class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix_vec;
        vector<int> suffix_vec(nums.size(),1);
        int temp_int = 1;
        vector<int> ans;
        int size = nums.size();


            for(int i = 0 ; i < size; i++){
                
                temp_int = temp_int * nums[i];
                prefix_vec.push_back(temp_int);
            }
        temp_int = 1;

            for(int i = size-1; i >= 0 ; i--){

                temp_int = temp_int * nums[i];
                suffix_vec[i] = temp_int;
            }
        temp_int = 1;

            for(int i = 0 ; i < size ; i++){
                if( i == 0){
                    ans.push_back(suffix_vec[i+1]);
                }else if(i == size-1){
                    ans.push_back(prefix_vec[i-1]);
                }else{
                    ans.push_back(prefix_vec[i-1] * suffix_vec[i+1]);
                }
            }
        
        return ans;
    }
};
