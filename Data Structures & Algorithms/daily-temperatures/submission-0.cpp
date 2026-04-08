class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans;
        for(auto itDay = temperatures.begin(); itDay != temperatures.end(); ++itDay){
            auto temp = find_if(itDay, temperatures.end(), [&](int x){
                return *itDay < x;
            });
            int addThisnum =0;
            if(temp != temperatures.end()) addThisnum = distance(itDay,temp);
            ans.push_back(addThisnum);
        }
        return ans;
    }
};
