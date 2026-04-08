class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int z = INT_MAX;

        for(int i = matrix.size()-1; i >= 0; i--){
            if(matrix[i][0] <= target){
                z = i;
                break;
            }
        }
        if(z == INT_MAX)return false;
        if(matrix[z][0]==target) return true;

        int i = 0; 
        int j = matrix[z].size() - 1;

        while (i <= j) {
            int mid = i + (j - i) / 2; // Correct way to find the middle

            if (matrix[z][mid] == target) {
                return true;
            } else if (matrix[z][mid] < target) {
                i = mid + 1; // Narrow search to the right half
            } else {
                j = mid - 1; // Narrow search to the left half
            }
        }
        return false;
    }
};
