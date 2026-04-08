class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        vector<int> arr(26, 0);      // Target counts from s1
        vector<int> window(26, 0);   // Current window counts in s2

        // 1. Initialize the first window
        for (int i = 0; i < s1.size(); i++) {
            arr[s1[i] - 'a']++;
            window[s2[i] - 'a']++;
        }

        // 2. Slide the window across the rest of s2
        for (int i = s1.size(); i < s2.size(); i++) {
            // Check if the previous window was a match
            if (arr == window) {
                return true;
            }

            // Add the new character entering the window on the right
            window[s2[i] - 'a']++;
            
            // Remove the old character that was left behind on the left
            window[s2[i - s1.size()] - 'a']--;
        }

        // Check the very last window after the loop ends
        return arr == window;
    }
};