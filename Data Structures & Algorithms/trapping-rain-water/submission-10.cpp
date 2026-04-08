class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 2){return 0;}
        int start = 0; 
        while(height.size() > start + 2 && height[start] <= height[start + 1]){
            // height.erase(height.begin());
            start++;
        }
        while(height.size() > 2 && height[height.size()-1] <= height[height.size() -2]){
            height.erase(height.end()-1);
        }
        if(height.size() <= 2){return 0;}


        int i = start; 
        int j = height.size() -1;
        int leftH = height[0];
        int candidate = 0;
        int ans =0;
        bool flag = false;
        

        while(i <= j){
            if(leftH <= height[i]){
                leftH = height[i];
                ans += candidate;
                candidate = 0;

                flag = false;
            }else{
                candidate += leftH - height[i];
                flag = true;
            }
            i++;
           
        }

        i = height.size() -2;
        j = height.size() -1;
        while(flag){
            if(height[i] >= height[j] && height[i] == leftH){
                break;
            }
            if(height[i] < height[j]){
                ans += height[j] - height[i];
            }
            i--;
        }
        return ans;
    }
};
