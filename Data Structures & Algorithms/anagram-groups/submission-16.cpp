class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<int, vector<string>> m;
        for(const string s : strs){
            m[(int)groupAnagrams_helper(s)].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto it = m.begin(); it != m.end(); ++ it){
            ans.push_back((*it).second);
        }

        return ans;
        
    }
    

    size_t groupAnagrams_helper(string s){
        vector<int> v(26,0);
        for(auto c : s){
            v[c - 'a']++;
        }
        size_t  h =0;
        for(int i = 0 ; i < 26; ++i){
            h ^= hash<int>{}(v[i]  + (h << 6) + (h >> 2));
        }
        return h;
    }
};
