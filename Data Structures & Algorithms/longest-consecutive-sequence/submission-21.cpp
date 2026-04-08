class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_map<int,int> m;

        for( auto n : nums){
            if(m[n])continue;
            int l = m[n-1];
            int r = m[n+1];

            m[n] = m[n -l] = m[n+r] = l + r + 1;
        }

        auto it = m.begin();
        int ans = 0;
        while( it != m.end()){
            if((*it).second > ans){
                ans = (*it).second;
            }
            ++it;
        }
        return ans;
    }
};
