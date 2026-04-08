class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {// no hashmap allowed
        int sum = 0;
        int l = 0; 
        int r = numbers.size() -1;
        

        while(l < r){
            int sum = numbers[l] + numbers[r];
            cout << sum << endl;
            if(sum == target){
                break;
            }
            if( sum > target){
                r--;
            }
            if(sum < target){
                l++;
            }
        }
        return { l + 1, r + 1};
        
    }
};
