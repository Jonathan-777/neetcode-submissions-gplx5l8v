class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        // int arr[127] = {0};
        int ans = 0;
        int size = s.size();
        unordered_map<int , int> m;
        int l = 0;
        int r = 0;

        for(int i = 0 ; i < size; i++){
            auto it = m.find(s[i]);
            if(it != m.end()){
                l = max(l, m[s[i]] + 1);;
            }
            m[s[i]] = i;
            ans = max( ans, (i - l) + 1);

        }

        return ans;
    }
};
