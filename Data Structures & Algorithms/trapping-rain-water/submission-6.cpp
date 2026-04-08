class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 2){return 0;}
        while(height.size() > 2 && height[0] <= height[1]){
            height.erase(height.begin());
        }
        while(height.size() > 2 && height[height.size()-1] <= height[height.size() -2]){
            height.erase(height.end()-1);
        }
        if(height.size() <= 2){return 0;}


        int i = 1; 
        int j = height.size() -1;
        int leftH = height[0];
        int candidate = 0;
        int ans =0;
        bool flag = false;
        

        while(i <= j){
            // vector<int> subHeight;
            if(leftH <= height[i]){
                leftH = height[i];
                ans += candidate;
                candidate = 0;
                // height.erase(height.begin() + i - 1);
                 cout<< "added to ans up to idx " << i << endl;
                // continue;
                flag = false;
            }else{
                candidate += leftH - height[i];
                cout<< "added +[" << leftH - height[i] << "] at idx " <<  i << endl;
                flag = true;
            }
            i++;
           
        }

        i = height.size() -2;
        j = height.size() -1;
        while(flag){
            cout<< "\nflaggg\n\n" ;
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
