class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        int maxArea = 0;
        if(heights.size() < 1) return 0;
        stack<int> stack;

        for(int i = 0; i <= size; i++){
            while(!stack.empty() && (i == size || heights[stack.top()] >= heights[i])){
                int length = heights[stack.top()];
                stack.pop();
                int width = (stack.empty())? i : i - stack.top() - 1; 
                maxArea = max(maxArea, length * width);
            }
            stack.push(i);
        }
        return maxArea;
    }
};
