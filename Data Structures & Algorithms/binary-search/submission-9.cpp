class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int range = distance(nums.begin() , nums.end()) / 2;
        if(nums.size() < 1) return -1;
        if(nums.size() == 1 && nums[0] != target) return -1;
        
        auto left_limit = nums.begin();
        auto right_limit = nums.end();

        auto it = nums.begin() + range;

        while(true){
            if(target == *it){
                return distance(nums.begin(), it);
            }

            // Check if it's safe to use prev/next to avoid crashing at boundaries
            if(it != left_limit && target < *it && *prev(it) < target){
                break;
            } else if(target < *it){
                if(it == left_limit) return -1;
                
                right_limit = it; // Update right boundary
                auto x = (distance(left_limit, it) + 1) / 2; // Calculate relative to left_limit
                advance(it, -x);
                continue;
            }

            if(next(it) != right_limit && target > *it && *next(it) > target){
                break;
            } else if(target > *it){
                if(next(it) == right_limit) return -1; // Boundary check for right side
                
                left_limit = it + 1; // Update left boundary
                auto x = (distance(it, right_limit)) / 2; // Calculate relative to right_limit
                advance(it, x);
                continue;
            }
        }
        return -1;
    }
};