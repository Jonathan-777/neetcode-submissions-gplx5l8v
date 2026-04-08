class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         if (nums.empty()) return 0;
        int best = 0;
        int ans = 0;
        
        set<int> s(nums.begin(), nums.end());
        

       
        nums.clear();
        nums.assign(s.begin(),s.end());
        int last = nums[0];

        for(int i = 1 ; i < nums.size(); i++){
            if(last + 1 == nums[i]){
                best++;
                if(best > ans)ans = best;
            }else{
                best = 0;
            }
            last = nums[i];
            
        }
        return ans+1;
    }
    
};