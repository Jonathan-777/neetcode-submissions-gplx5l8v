class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<int,vector<string>> m;
        for(auto x: strs){
            m[compute_hash(x)].push_back(x);
        }
        vector<vector<string>> ans;

        for(auto it = m.begin() ; it!= m.end(); ++it ){
            ans.push_back((*it).second);
        }
        return ans;
    }

    size_t compute_hash(string strs){

        vector<int> vec(26,0);
        for(auto x: strs){
            vec[x - 'a']++;
        }
        
        size_t h =0;


        for(int i = 0; i < vec.size(); i++){
            h ^= hash<int>{}(vec[i]) + 0x9e3779b9 + (h<< 6) + ( h >> 2);
        }
        return h;
    }
};
