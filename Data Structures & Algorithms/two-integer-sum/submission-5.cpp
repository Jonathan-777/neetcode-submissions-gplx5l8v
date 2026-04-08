class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;

        for( int i = 0; i < nums.size(); i++){
            int temp = target - nums[i];
            unordered_map<int,int>::iterator it; 
            it = m.find(temp);
            if(it != m.end()){
                return {(*it).second, i};
            }
            m.try_emplace(nums[i], i);
        }
        return {};
    }
};
