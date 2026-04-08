class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int size = nums.size();
        unordered_map<int,int> m;
        vector<int> ans;

        for(auto &x : nums){
            m[x]++;
        }

        for(int i = 0; i < size; i++){
            if(k <= 0) break;
            auto it = max_element(m.begin(), m.end(), [](const auto &a, const auto &b){
                                    return a.second < b.second;
            });

            if(it != m.end()){
                ans.push_back(it->first);
                m.erase(it);
                k--;
            }
        }

        return ans;
    }
};
