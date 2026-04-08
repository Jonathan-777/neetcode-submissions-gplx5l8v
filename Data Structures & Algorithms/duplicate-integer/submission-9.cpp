class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int size = nums.size();
        unordered_set<int> s;
        for(auto x : nums){
            if(!s.insert(x).second){
                return true;
            }
        }
        return false;
    }
};