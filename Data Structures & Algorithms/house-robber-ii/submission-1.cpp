class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() <=1)return nums[0];
        vector<int> nums1(nums.begin(), nums.end()-1);
        vector<int> nums2(nums.begin()+1, nums.end());
        return max(rob_helper(nums1),rob_helper(nums2));
        
    }
    int rob_helper(vector<int>& nums){
        int house1 = 0, house2 = 0;

        for(int num : nums){
            int temp = max(num + house1 , house2);
            house1 = house2;
            house2 = temp;
        }
        return max(house1,house2);
    }
};
