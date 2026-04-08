class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i = 0; i < nums.size(); i++){
            int need = target - nums[i];
            auto it = m.find(need);
            if(it != m.end()){
                int j = it->second;
                return {j, i};
            }
            m.try_emplace(nums[i],i);
        }
        return {};
    }
};
