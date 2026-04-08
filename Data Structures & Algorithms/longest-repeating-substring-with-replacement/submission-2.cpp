class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> count;
        int ans = 0;
        int max_count;
        int l = 0;
        for(int r = 0; r < s.size(); r++){
            count[s[r]]++;// window count for curr element
            max_count = max(max_count, count[s[r]]);// how we check if the item matches the majority
            cout << r << " - " << l  <<" + " << 1 << " -(" << max_count << ") > " << k <<   " = " << (r - l + 1) - (max_count) << " < " << k << endl;
            while((r - l + 1) - (max_count) > k){ // we check k against max_count in the window **** order of operations was the only source of confusion
                cout << "inside" << endl;
                count[s[l]]--;// remove from back of the window
                l++;

            }
            ans = max(ans,r - l +1);
        }
        return ans;
    }
};
