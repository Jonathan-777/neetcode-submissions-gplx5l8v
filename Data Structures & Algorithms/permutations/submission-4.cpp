class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }



    void backtrack(vector<int>& nums, int idx) {


    if (idx == nums.size()) {
        res.push_back(nums);
        return;
    }


    for (int i = idx; i < nums.size(); i++) {
        // Only XOR swap if the addresses are different
        if (idx != i) {
           swap(nums[idx],nums[i]);
        }

        backtrack(nums, idx + 1);

        // Backtrack the swap
        if (idx != i) {
            swap(nums[idx],nums[i]);
        }
    }
}
};