class Solution {
public:
    int trap(vector<int>& height) {// monotonic stack approach
        stack<int> index_stack;
        int size = height.size();
        int ans = 0;

        for(int i = 0; i < size; i++){
            while(!index_stack.empty() && height[i] > height[index_stack.top()] ){
                int mid = index_stack.top();//bottom of candidate pocket 
                index_stack.pop();
                if(index_stack.empty())break;
                int left = index_stack.top();
                int right = i; // 

                int h = min(height[right], height[left])- height[mid];
                int w = right  - left -1;

                ans += h*w;


            }
            index_stack.push(i);
        }
        return ans;
    }
};
