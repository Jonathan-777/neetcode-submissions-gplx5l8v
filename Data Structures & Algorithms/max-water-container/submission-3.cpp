class Solution {
public:
    int maxArea(vector<int>& heights) {
        int size = heights.size();
        int l = 0;
        int r = size-1;
        int ans = 0;

        while(l < r){
            int smallest = min(heights[l], heights[r]);
            ans = max(ans, smallest * (r - l));
            if(smallest == heights[l]){
                l++;
            }else{
                r--;
            }
        }
        return ans;
    }
};
