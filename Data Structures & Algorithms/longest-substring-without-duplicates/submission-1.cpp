class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        int ans = 0;
        unordered_map<char,int> m;
        int L = 0;
        int r = 0;

        for(int i = 0 ; i  < size ; i++){
        // If s[i] was seen before, move 'l' to one past its last position
        // (ensures current window has unique characters only)
        if (m.count(s[i])) L = max(L, m[s[i]]);
            ans = max(ans, i - L + 1);
            m[s[i]] = i + 1;
        }
        return ans;
    }
};
