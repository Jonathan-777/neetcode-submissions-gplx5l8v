using test = int;
class Solution {
public:
    test largestRectangleArea(vector<test>& heights) {
        stack<test> s;
        test size = heights.size();
        test ans = 0;

        for(test i=0; i <= size; i++){// goal is to calculate the item before i, ie the thing on the top of the stack
            while(!s.empty() && (i == size || heights[i] <= heights[s.top()]) ){
                test h = heights[s.top()];
                s.pop();
                test w = (s.empty())? i : i - s.top() -1;
                ans = max(ans, h*w);

            }
            s.push(i);
            
        }
        return ans;
    }
};
