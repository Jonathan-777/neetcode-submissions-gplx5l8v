class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        unordered_set<int> bitMap;


        for(auto x : nums){
            if(!bitMap.insert(x).second){
                return true;
            }
        }
        return false;
    }
};