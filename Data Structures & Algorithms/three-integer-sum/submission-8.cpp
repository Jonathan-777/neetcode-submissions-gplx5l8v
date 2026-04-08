class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Step 1: Sort the array to easily enforce ordering and spot duplicates
        sort(nums.begin(), nums.end()); 
        
        unordered_map<int,int> m;
        for(auto x: nums){
            m[x]++;
        }
        
        vector<vector<int>> ans;
        int size = nums.size();
        
        for(int i = 0; i < size; i++){
            // Rule 1: Skip duplicate starting numbers, but keep the map balanced!
            if (i > 0 && nums[i] == nums[i-1]) {
                m[nums[i]]--; 
                continue;
            }
            
            int current = nums[i];
            m[current]--;

            // Track the last successfully used middle number to prevent duplicates
            int last_z_val = INT_MIN; 

            for(int z = i+1; z < size; z++){
                auto it = m.find(nums[z]);
                if((*it).second <= 0){
                    continue;
                }

                m[(*it).first]--;
                
                int two_sum = current + (*it).first;
                two_sum *= -1;
                auto it_3 = m.find(two_sum);
                
                // Rule 2 & 3: 
                // - two_sum < nums[z]: enforces current <= nums[z] <= two_sum
                // - nums[z] == last_z_val: prevents using the same middle number twice
                if(it_3 == m.end() || (*it_3).second <= 0 || two_sum < nums[z] || nums[z] == last_z_val){
                    continue;
                }
                
                m[two_sum]--;
                
                ans.push_back({current, (*it).first, two_sum});
                last_z_val = nums[z]; // Record successful middle number
            }

            // Your flawless map restoration loop remains untouched
            for(int z = i+1; z < size ; z++){
                m[nums[z]]++;
            }
        }
        return ans;
    }
};