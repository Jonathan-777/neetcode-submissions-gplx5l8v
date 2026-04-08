class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> counts;
        for (int x : nums) counts[x]++;

        // We use a set of vectors to automatically handle duplicate triplets
        set<vector<int>> uniqueTriplets;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // "Virtually" remove the first element so we don't reuse it
            counts[nums[i]]--; 

            for (int j = i + 1; j < n; j++) {
                // "Virtually" remove the second element
                counts[nums[j]]--;

                int target = 0 - (nums[i] + nums[j]);
                
                // Check if the third element exists in the remaining counts
                if (counts.count(target) && counts[target] > 0) {
                    vector<int> triplet = {nums[i], nums[j], target};
                    // Sort the triplet so {-1, 0, 1} and {0, -1, 1} look identical
                    sort(triplet.begin(), triplet.end());
                    uniqueTriplets.insert(triplet);
                }

                // Put the second element back for the next 'j' iteration
                counts[nums[j]]++;
            }
            // Put the first element back for the next 'i' iteration
            counts[nums[i]]++;
        }

        // Convert the set back to the required vector format
        return vector<vector<int>>(uniqueTriplets.begin(), uniqueTriplets.end());
    }
};