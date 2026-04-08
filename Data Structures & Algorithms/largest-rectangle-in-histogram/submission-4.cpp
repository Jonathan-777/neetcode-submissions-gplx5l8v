class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        stack<int> s;
        int size = heights.size();
        if(size < 1)return 0;

        for(int i = 0 ; i <= size; i++){

            while(!s.empty() && ( i == size  || heights[i] <= heights[s.top()]) ){
                int h = heights[s.top()];
                s.pop();
                int w = (s.empty())? i : i - s.top() - 1;
                ans = max(ans, h*w);

            }
            s.push(i);
        }
        return ans;
    }
};
