class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int size = nums.size();
        // aim for better running time
        unordered_map<int,int> m ;
        vector<int> ans;

        for(auto &x : nums){
            m[x]++;
        }
        while( k > 0){
            auto it = max_element(m.begin(), m.end(), [](const auto &a, const auto &b){
                                return a.second < b.second;
            });
            
            ans.push_back(it->first);
            m.erase(it->first);
            k--;

        }

     return ans;

    }
};
