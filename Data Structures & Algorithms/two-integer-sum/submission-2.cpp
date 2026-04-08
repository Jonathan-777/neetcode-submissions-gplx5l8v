class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        unordered_map<int,int> m;
        int counter = 0;

        for(auto &x : nums){
            m[target - nums[counter]] = counter;
            counter++;
        }
        
        for(int i = 0 ; i < size; i++){
            int temp = nums[i];
            auto iterator = m.find(temp);
            if(iterator !=  m.end() &&  iterator->second != i){
                return {i, iterator->second};
            }
        }
        return {};
    }
};
