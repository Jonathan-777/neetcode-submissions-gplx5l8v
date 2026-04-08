class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> sorted;
        for(auto &x : nums){
            sorted.insert(x);
        }

        return (sorted.size() == nums.size()) ? false : true;
    }
};