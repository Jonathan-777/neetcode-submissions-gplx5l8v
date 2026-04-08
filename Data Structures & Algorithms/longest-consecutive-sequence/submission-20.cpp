class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())return 0;
        set<int> s;
        int ans = 0;

        for(auto x: nums){
            s.insert(x);
        }

        vector<int> v(s.size(),1);
        int i = 0;

        for(auto it = s.begin(); it != s.end(); ++it){
            if(it != s.begin()){
                auto last = prev(it);
                if(*last == (*it)-1){
                    v[i] = v[i-1] + 1;
                }
            }else{
                
            }
            i++;
        }

        for(auto x : v){
            if(ans < x){
                ans = x;
            }
        }
        return ans;
    }
};
