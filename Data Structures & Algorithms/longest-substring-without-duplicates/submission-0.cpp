class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        int ans = 0;
        unordered_map<char,int> m;
        int l = 0;
        int r = 0;

        for(int i = 0 ; i  < size ; i++){
        if (m.count(s[i])) l = max(l, m[s[i]]);
            ans = max(ans, i - l + 1);
            m[s[i]] = i + 1;
        }
        return ans;
    }
};
