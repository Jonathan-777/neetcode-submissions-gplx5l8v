class Solution {
public:
    int maxArea(vector<int>& heights) {

        int i = 0;
        int j = heights.size() -1;

        int maxH = 0;

        while(i < j){
            if(heights[i] < heights[j]){
                if(maxH < (j-i)* heights[i]){
                    maxH =  (j-i)* heights[i];
                    
                }
                i++;
            }
            if(heights[j] <= heights[i]){
                if(maxH < (j-i)*heights[j]){
                    maxH = (j-i)*heights[j];
                }
                j--;
            }

        }

        while(i < j){
            if(heights[i] <= heights[j]){
                if(maxH < (j-i)* heights[i]){
                    maxH =  (j-i)* heights[i];
                    
                }
                i++;
            }
            if(heights[j] < heights[i]){
                if(maxH < (j-i)*heights[j]){
                    maxH = (j-i)*heights[j];
                }
                j--;
            }

        }
        return maxH;
    }
};
