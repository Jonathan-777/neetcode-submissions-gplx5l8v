class Solution {
public:
    int maxArea(vector<int>& heights) {
        int size = heights.size();
        int l = 0; 
        int r = size - 1;
        int best = 0;
        

        while(l < r){
            int smallest = (heights[l] < heights[r]) ? heights[l] : heights[r];
            int temp = ((r - l)* (smallest));
            if(best < temp) best = temp;
            if(heights[l] > heights[r]){
                r--;
            }else{
                l++;
            }
            
        }
        return best;
    }
};
