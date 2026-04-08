class Solution {
    private: 
    vector<vector<int>> ans;
    public:
        
        vector<vector<int>> permute(vector<int>& nums) {
            permute_helper(*this, nums,nums.size(), 0);
            return ans;        
        }

    friend void permute_helper(Solution& sol, vector<int>& nums, int size, int index);


    };
    void permute_helper(Solution& sol, vector<int>& nums, int size, int index){
        if(size == index){  // guard against out of bounds
            sol.ans.push_back(nums);
            return;
        }

        for(int i = index ; i < nums.size(); i++){

            if(index != i)swap(nums[i], nums[index]);// if statements guard against swapping w/ itself

            permute_helper(sol, nums, size, index + 1);// +1 avoids repeats

            if(index != i)swap(nums[i], nums[index]);

        }




    }