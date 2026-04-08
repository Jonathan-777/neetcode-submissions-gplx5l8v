class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> s;

        for(auto x : nums){
            if(!s.insert(x).second){
                    return true;
            }
        }
        return false;
    }
};