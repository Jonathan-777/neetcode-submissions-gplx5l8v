class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;

        for(auto it = nums.begin() + k; it <= nums.end(); ++it){
            auto left = it - k;
            cout << "Window from index " << distance(nums.begin(), left) 
                 << " to " << distance(nums.begin(), it - 1) 
                 << " (Values: " << *left << " to " << *(it - 1) << ")" << endl;
                 
            auto temp = max_element(left,it);
            ans.push_back(*temp);
            
        }
     return ans;   
    }
};
