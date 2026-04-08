class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<string> copy = strs;
        for( auto& x : copy){
            sort(x.begin(), x.end()); // only sort each string inside the index of vec, preserving their original order in the vec
        }
        for(int i = 0 ; i < strs.size() ; i++){
            vector<string> temp;
            int size = copy.size();
            for(int z = size - 1; z > i; z--){
                if(copy[z] == copy[i]){
                    temp.push_back(strs[z]);
                    copy.erase(copy.begin() + z);
                    strs.erase(strs.begin() + z);

                }
            }
            temp.push_back(strs[i]);
            ans.push_back(temp);
        }
        return ans;
    }
};
