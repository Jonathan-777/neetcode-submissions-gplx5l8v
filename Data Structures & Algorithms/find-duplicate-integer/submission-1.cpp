class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> s;
        for(auto x: nums){
            if(!s.insert(x).second){
                return x;
            }
        }
        return -1;
    }
};
