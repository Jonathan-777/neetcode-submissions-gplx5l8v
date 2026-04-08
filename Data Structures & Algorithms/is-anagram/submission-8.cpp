class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> ans(26,0);

        for(auto x: s){
            int temp = x - 'a';
            ans[temp]++;
        }

        for(auto x: t){
            int temp = x - 'a';
            if(ans[temp] > 0){
                ans[temp]--;
            }else{
                return false;
            }
        }

        for(auto x : ans){
            if(x > 0){
                return false;
            }
        }
        return true;
    }
};
