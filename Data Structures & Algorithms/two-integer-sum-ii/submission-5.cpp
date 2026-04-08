class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        vector<int> ans;
        for(int i = 0 ; i < numbers.size()-1; i++){
            int need = target - numbers[i];
            for(int z = i + 1 ; z < numbers.size(); z++){
                if(numbers[z] == need){
                    ans.push_back(i+1);
                    ans.push_back(z+1);
                    return ans;
                }
            }
        }
        return ans;
    }
};
