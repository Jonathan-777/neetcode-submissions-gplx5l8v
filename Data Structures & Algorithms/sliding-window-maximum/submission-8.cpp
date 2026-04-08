class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // Stores INDICES
        vector<int> ans;
        int size = nums.size();

        for (int i = 0; i < size; ++i) {
            // 1. Remove indices that are out of the window boundary
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // 2. Remove elements smaller than the current one (Monotonic Property)
            // If nums[i] is bigger, the elements currently in dq can NEVER be the max
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // 3. Once we've hit the first window size, start recording results
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};