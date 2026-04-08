class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int ans = 0;
        
        for (int i = 0; i < height.size(); i++) {
            // While the current bar is taller than the bar at the top of the stack
            while (!st.empty() && height[i] > height[st.top()]) {
                int mid = st.top(); // The 'bottom' of the potential water pocket
                cout << "Index at top: " << st.top() << " | Height at top: " << height[st.top()] << "   height at i : " << height[i] << endl;
                st.pop();
                
                if (st.empty()) break; // No left wall to trap water
                
                int left = st.top();
                int right = i;
                
                // Calculate bounded height and width
                int h = min(height[right], height[left]) - height[mid];
                int w = right - left - 1;
                
                ans += h * w;
            }
            st.push(i);
        }
        return ans;
    }
};