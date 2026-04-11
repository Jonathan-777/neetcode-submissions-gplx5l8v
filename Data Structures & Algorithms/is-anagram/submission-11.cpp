class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v(26,0);

        for(const auto c : s){
            v[c - 'a']++;
        }
        for(const auto c : t){
            v[c - 'a']--;
        }
        for(const int x : v){
            if(x != 0)return false;
        }
        return true;
    }
};
