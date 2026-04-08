class Solution {
public:
    int findDuplicate(vector<int>& nums) {//another poorly worded problem
        int n = nums.size() - 1;
        
        // Step 1: Create our buckets
        // We need n + 1 buckets so the indices match the numbers exactly (1 to n)
        // Each bucket will store the count of how many times that number appears
        std::vector<int> buckets(n + 1, 0);
        
        // Step 2: The Distribution Phase
        // Drop each number into its corresponding bucket by increasing the count
        for (int num : nums) {
            buckets[num]++;
        }
        int writeIndex = 0;
        
        for (int i = 1; i <= n; i++) {
            // While a bucket still has items in it, write that number to the array
            while (buckets[i] > 0) {
                nums[writeIndex] = i;
                writeIndex++;
                buckets[i]--; // Remove the item from the bucket
            }
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == nums[i+1]){
                return nums[i];
            }
            
        }
        return -1;
        
    }
};
