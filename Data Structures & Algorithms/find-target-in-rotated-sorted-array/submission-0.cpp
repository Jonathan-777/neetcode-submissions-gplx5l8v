class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) return mid;

            // Step 1: Identify the sorted half
            if (nums[l] <= nums[mid]) {
                // Left half [l...mid] is sorted
                if (target >= nums[l] && target < nums[mid]) {
                    r = mid - 1; // Target is in the sorted left half
                } else {
                    l = mid + 1; // Target is in the right half
                }
            } else {
                // Right half [mid...r] is sorted
                if (target > nums[mid] && target <= nums[r]) {
                    l = mid + 1; // Target is in the sorted right half
                } else {
                    r = mid - 1; // Target is in the left half
                }
            }
        }
        return -1;
    }
};