class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int size = numbers.size();
        int best = 0;
        tuple<int,int> a;
        int j = size -1;
        int i = 0;


        while(i < j){
            
            if((numbers[i] + numbers[j]) == target){
                 return {i +1, j+1};
            }else if((numbers[i] + numbers[j]) > target ){
                j--;
                continue;
            }else if((numbers[i] + numbers[j]) < target ){
                i++;
                continue;
            }

        }
        return {1,1};
    }
};
