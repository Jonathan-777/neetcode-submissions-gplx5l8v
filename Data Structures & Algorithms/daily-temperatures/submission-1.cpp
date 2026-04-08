class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {// fastest solution i can think of is log n, but monotonic stack gets us 0(n)

        int size = temperatures.size();

        stack<int> s;

        vector<int> ans(size,0);

        for(int i =0; i < size; i++){

            int currentNum = temperatures[i];
            while(!s.empty() && currentNum > temperatures[s.top()]){
                ans[s.top()] = i - s.top();
                s.pop();

            }
            s.push(i);
        }

        return ans;
        
    }
};
