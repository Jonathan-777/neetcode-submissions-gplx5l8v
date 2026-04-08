class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset <int> set_window;
        int l = 0;
        int size = nums.size();
        for(int i = 0; i < k; i++){
            set_window.insert(nums[i]);
        }
        vector<int> ans;
        ans.push_back(*set_window.rbegin());

        for(int r = l + k; r < size; r++){
            // if(r - l + 1 != k){
            //     throw runtime_error("window is != k" );
            // }
            
            // set_window.erase(nums[l]);  // removes all duplicates 
            
            
            auto it_forward = set_window.find(nums[l]);
            set_window.erase(it_forward);
            l++;

            set_window.insert(nums[r]);


            auto it = set_window.rbegin();
            ans.push_back(*it);
            
        }
        return ans;
        
    }
};
