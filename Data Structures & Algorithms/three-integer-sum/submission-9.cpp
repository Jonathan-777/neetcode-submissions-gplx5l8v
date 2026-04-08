class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,int> m;
        sort(nums.begin(),nums.end());
        for(auto x: nums){
            m[x]++;
        }
        vector<vector<int>> ans;
        int size = nums.size();
        int current = INT_MIN;
        for(int i = 0; i < size; i++){
            if (i > 0 && nums[i] == nums[i-1]) {
                    m[nums[i]]--; 
                    continue;
            }

            current = nums[i];
            m[current]--;
            int last_z_val = INT_MIN;

            for(int z = i+1; z < size; z++){
                
                auto it = m.find(nums[z]);
                if( (*it).second <= 0){
                    continue;
                }


                m[(*it).first]--;
                
                int two_sum = current + (*it).first;
                two_sum *= -1;
                auto it_3 = m.find(two_sum);

                if(it_3 == m.end() || (*it_3).second <= 0|| (*it_3).second <= 0 || two_sum < nums[z] || nums[z] == last_z_val){
                    continue;
                }
                m[two_sum]--;

                ans.push_back({(*it).first, (*it_3).first, current});
                last_z_val = nums[z];

            }

            for(int z = i+1; z < size ; z++){
                m[nums[z]]++;
            }

        }
        return ans;
    }
};
