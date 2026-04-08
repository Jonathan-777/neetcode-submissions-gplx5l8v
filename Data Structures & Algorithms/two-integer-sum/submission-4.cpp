class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        
        
        for(int i = 0 ; i < nums.size(); i++){
            int need = target - nums[i];
            if(auto it = m.find(need); it != m.end()){
                return{it->second,i};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};
