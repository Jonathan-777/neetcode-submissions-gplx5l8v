class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(auto x: nums){
            m[x]++;
        }
        vector<int> ans;
        set<pair<int,int>> ans_helper;

        for(auto it = m.begin(); it != m.end(); ++it){
            ans_helper.insert({(*it).second, (*it).first});
        }

        set<pair<int,int>>::const_reverse_iterator it = crbegin(ans_helper);
        while(k > 0){
            
            ans.push_back((*it).second);
            ++it;
            k--;
        }
        return ans;
    }
};
