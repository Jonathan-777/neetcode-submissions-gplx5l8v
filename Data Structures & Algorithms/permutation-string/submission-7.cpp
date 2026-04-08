class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> s1_count(26, 0);
        vector<int> window_count(26, 0);

        // Fill frequency for s1 and the first window of s2
        for (int i = 0; i < s1.size(); i++) {
            s1_count[s1[i] - 'a']++;
            window_count[s2[i] - 'a']++;
        }

        // Slide the window across s2
        for (int i = 0; i < s2.size() - s1.size(); i++) {
            if (s1_count == window_count) return true;

            // Move window: remove leftmost char, add next char on right
            window_count[s2[i] - 'a']--;
            window_count[s2[i + s1.size()] - 'a']++;
        }

        // Check the very last window
        return s1_count == window_count;
    }
};