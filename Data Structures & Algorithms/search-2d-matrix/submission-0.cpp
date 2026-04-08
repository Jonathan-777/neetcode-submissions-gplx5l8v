class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool ans = false;
        
        for(int i = 0; i < matrix.size(); i++){
            auto it = matrix.begin() + i;
            if(*it->begin() > target){
                break;
            }
            auto found = find(it->begin(), it->end(),target);
            if(found != it->end() ){
                return true;
            }

        }
        return ans;
    }
};
