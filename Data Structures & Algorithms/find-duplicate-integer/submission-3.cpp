class Solution {
public:
    int findDuplicate(vector<int>& nums) {// this solution is not as robust as using a hash_set but this one saves some memory
        // Phase 1: Finding the intersection point in the cycle
        int tortoise = nums[0];
        int hare = nums[0];
        
        do {
            tortoise = nums[tortoise];          // Moves 1 step
            hare = nums[nums[hare]];            // Moves 2 steps
        } while (tortoise != hare);

        // Phase 2: Finding the entrance to the cycle (the duplicate)
        tortoise = nums[0];
        while (tortoise != hare) {
            tortoise = nums[tortoise];          // Moves 1 step
            hare = nums[hare];                  // Moves 1 step
        }
        
        return hare;
    }
};