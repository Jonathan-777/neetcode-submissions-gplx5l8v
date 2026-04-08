class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if(size < 3) return 0;
        int sum = 0;
        int j  = 0; 
        int k = size-1;
        int temp = height[0];

        for(auto &x: height){
            if(temp > x)break;
            if(temp < x) j++;
            temp = x;
        }
            temp = height[k];
        for(int i = size-1 ; i >= 0; i--){
            if(temp > height[i])break;
            if(temp < height[i])k--;
            temp = height[i];
        }

        // at this point we cut off the edges.

        if( j == size-1 || k == 0) return 0;


        // two-pointer accumulation between j and k (minimal structural change)
        int left = j, right = k;
        int leftMax = height[left], rightMax = height[right];
        while (left < right) {
            if (leftMax <= rightMax) {
                ++left;
                leftMax = max(leftMax, height[left]);
                sum += max(0, leftMax - height[left]);
            } else {
                --right;
                rightMax = max(rightMax, height[right]);
                sum += max(0, rightMax - height[right]);
            }
        }
        return sum;
    }
};
