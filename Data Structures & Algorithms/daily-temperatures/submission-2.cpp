class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> s;
        int size = temperatures.size();
        vector<int> ans(size);

        for(int i = size -1; i >= 0; i--){
            
            while( !s.empty() && s.top().first <= temperatures[i]){
                s.pop();
            }
            if(s.empty()){
                ans[i] = 0;
                s.push({temperatures[i],i});
                continue;
            }

            int dist = (s.top().second) - i ;
            ans[i] = dist;
            s.push({temperatures[i],i});

        }
        return ans;
    }
};
