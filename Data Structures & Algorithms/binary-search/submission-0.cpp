class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto num = find(nums.begin(), nums.end(),target);
        if(num == nums.end()){
            return -1;
        }
        return distance(nums.begin(), num);
    }
};
