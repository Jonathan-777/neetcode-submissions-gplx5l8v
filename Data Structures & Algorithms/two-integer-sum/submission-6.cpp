class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        int size = nums.size();

        for( int i = 0 ; i < size; i++){
            int temp = target - nums[i];
            auto it = m.find(temp);
            if(it != m.end()){
                return {(*it).second, i};
            }
            m.try_emplace(nums[i], i);
        }

        return {};
        
    }
};
