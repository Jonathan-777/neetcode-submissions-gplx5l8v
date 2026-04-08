class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        auto itBegin = nums.begin();
        auto itEnd = nums.begin() +k;

        while(itEnd < nums.end()+1){
           auto temp = max_element(itBegin,itEnd);
           ans.push_back(*temp);

           itBegin++;
           itEnd++;
           
        }
        return ans;
    }
};
