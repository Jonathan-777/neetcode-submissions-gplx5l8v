class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> u_set;

        for(auto x : nums){
            if(!u_set.insert(x).second){
                    return true;
            }
        }
        return false;
    }
};