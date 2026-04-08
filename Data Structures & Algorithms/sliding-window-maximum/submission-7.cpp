class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {// very easy problem, but it must be as efficient as possible
    
        
        auto it_l = nums.begin();
        auto it_r = nums.begin();
        vector<int> ans;

        auto custom_set_comparison = [](const vector<int>::iterator& a, const vector<int>::iterator& b){
                if (*a != *b) return *a < *b; // Sort by value
                return a < b;
        };

        multiset<vector<int>::iterator, decltype(custom_set_comparison)> s(custom_set_comparison);

        while(it_r != nums.begin() + k){
            s.insert(it_r);
            it_r = next(it_r);
        }

        
        ans.push_back(**s.rbegin());

        while(it_r != nums.end()){
     
        
            s.insert(it_r);
            s.erase(it_l);
            it_l = next(it_l);
            it_r = next(it_r);


            ans.push_back(**s.rbegin());
        }



        return ans;
       

        
    }
};
