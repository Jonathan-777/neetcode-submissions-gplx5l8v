class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {// rolling polynomial hash 
        unordered_map<size_t, vector<string>> groups;
        
        for(const string& s : strs){
            groups[computeHash(s)].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto& entry : groups){
            ans.push_back(move(entry.second));
        }
        return ans;
    }

    private:

    size_t computeHash(const string& s){
        
        int count[26] = {0};
        for(char c : s) {
            count[c - 'a']++;  // 'b' - 'a'
        }

        size_t h = 0;

        for(int i = 0; i < 26 ; i++){
            h ^= hash<int>{}(count[i]) + 0x9e3779b9 +  (h << 6) + (h >> 2);
        }

        return h;


    }
};
