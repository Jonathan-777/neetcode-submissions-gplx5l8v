class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> count;
        int res = 0, L = 0,  max_frequencies = 0;

        for(int r = 0; r < s.size(); r++){
            count[s[r]]++;
            max_frequencies = max(max_frequencies, count[s[r]]);

                while((r - L + 1) - max_frequencies > k){
                    count[s[L]]--;
                    L++;
                }
            res = max(res, r - L + 1);
        }

        return res;
    }
};
