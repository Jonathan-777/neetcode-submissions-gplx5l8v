class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> ans;
        for( auto x : nums){
            ans.insert(x);
        }
        if (ans.empty()) return 0;
        if(ans.size() ==1) return 1;
        int max_candidate = 1;
        vector<int> answer;
        
        for(auto it = ans.begin(); next(it) != ans.end();it++){
            auto next_it = ans.begin();
            if(ans.size() > 1) next_it = next(it);
            int nextItem = INT_MIN;
            if (next_it != ans.end() && ans.size() > 1) {
                 nextItem = *next_it;
            }
            if(*it +1 == nextItem){
                max_candidate++;
            }else{
                if(it == prev(ans.end())){
                    if(*it - 1 == *prev(it) && ans.size() > 1){
                        max_candidate++;
                    }
                }else{
                     max_candidate = 1;
                }
            }
            answer.push_back(max_candidate);

        }
        auto it = max_element(answer.begin(), answer.end());
        return *it;
    }
};
