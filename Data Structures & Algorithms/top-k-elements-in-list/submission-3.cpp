class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        vector<int> ans;
        for(auto x: nums){
            m[x]++;
        }
        for(int i = k ; i > 0; i--){
            int frequent  = INT_MIN;
            int key_freq = 0;
            for(auto it = m.begin(); it != m.end(); it++){
                if(frequent  < it->second){
                    frequent = it->second;
                    key_freq = it->first;
                }
            }
            auto iter = m.find(key_freq);
            ans.push_back(iter->first);
            if(iter != m.end()){
                m.erase(iter);
            }
        }
        return ans;
    }
};
