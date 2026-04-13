class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> m;

    // 1. Count frequencies
    for(const auto num : nums){
        m[num]++;
    }

    // 2. Overwrite the beginning of 'nums' with unique elements from the map
    int unique_count = 0;
    for(auto it = m.begin(); it != m.end(); ++it){
        nums[unique_count++] = it->first;
    }

    // 3. Partially sort the first 'unique_count' elements in-place.
    // We use a lambda function to sort descending based on map values.
    nth_element(nums.begin(), nums.begin() + k, nums.begin() + unique_count, 
        [&m](int a, int b) {
            // Compare frequencies of element 'a' and element 'b'
            return m.at(a) > m.at(b); // return kth biggest elements
        }
    );

    // 4. Return the first k elements. 
    // (This is the only new structure created, strictly to satisfy the return type)
    return vector<int>(nums.begin(), nums.begin() + k);
}
};
