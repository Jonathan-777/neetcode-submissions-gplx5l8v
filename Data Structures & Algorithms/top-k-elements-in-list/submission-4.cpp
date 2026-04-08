class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        priority_queue<pair<int,int>,vector<pair<int,int>>  > pq;// [freqency, num]
        vector<int> ans;

        for(auto x: nums){
            m[x]++;

        }

        for(auto it = m.begin(); it != m.end(); ++it){
            pq.push({it->second, it->first});
        }

        for(int i = 0; i < k; i++){
            ans.push_back(pq.top().second);
            pq.pop();

        }
        
        return ans;

        
    }
};
