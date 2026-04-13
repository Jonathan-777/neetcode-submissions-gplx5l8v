class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();

        vector<int> prefix;
        vector<int> suffix(size);
        int product =1;
        

        for(int i = 0; i < nums.size(); i++){
            product *= nums[i];
            prefix.push_back(product);
            
        }
        product =1;
        for(int i = size-1; i >= 0; i--){
            product *= nums[i];
            suffix[i] = product;
            
        }

        for(int i = 0; i < size; i++){
            if(i > 0 && i < size -1){
                nums[i] = (prefix[i-1] * suffix[i+1]);
            }else if(i == 0){
                nums[i] = suffix[i+1];
            }else{
                nums[i] = prefix[i-1];
            }
        }
        return nums;

    }
};
