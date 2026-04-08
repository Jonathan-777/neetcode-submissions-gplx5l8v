class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> prefix(size,1);
        prefix[0] = nums[0];
        vector<int> suffix(size,1);
        suffix[size-1] = nums[size-1];
        

        for(int i = 1; i < size; i++){
            prefix[i] =  nums[i] * prefix[i-1];
        }

        for(int i = size-2; i >= 0; i--){
            suffix[i] = nums[i] * suffix[i+1];
        }
        nums[0] = suffix[1];
        nums[size-1] = prefix[size-2];

        if(size == 2) return nums;

        for(int i = 1; i <= size-2; i++){
            nums[i] = prefix[i-1] * suffix[i+1];
        }

        

        return nums;
    }
};
