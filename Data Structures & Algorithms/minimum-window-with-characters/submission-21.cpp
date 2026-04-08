class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        // An array of 128 integers acts as a lightning-fast map for ASCII characters
        vector<int> map(128, 0);
        
        // Populate requirements
        for (char c : t) {
            map[c]++;
        }

        int l = 0, r = 0;
        int minStart = 0, minLen = INT_MAX;
        
        // Instead of unique chars, we just track the total required characters
        int counter = t.length(); 

        while (r < s.length()) {
            // If this character is required (value > 0), decrement our counter
            if (map[s[r]] > 0) {
                counter--;
            }
            // Always decrease the map value, even for useless characters.
            // Useless characters will become negative numbers!
            map[s[r]]--;
            r++;

            // When counter == 0, our window contains all required characters
            while (counter == 0) {
                // Update the minimum window if we found a shorter one
                if (r - l < minLen) {
                    minStart = l;
                    minLen = r - l;
                }

                // Shrink the window from the left
                map[s[l]]++; // Put the character back into the map

                // If putting it back made the map value > 0, it means we 
                // just threw away a character we actually needed!
                if (map[s[l]] > 0) {
                    counter++; // Window is invalid again, break the while loop
                }
                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};