class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int size = strs.size();
        vector<vector<string>> ans;
        vector<string> copy = strs;

        for(auto &x: copy){
            sort(x.begin(), x.end());
        }

        for(int i = 0; i < copy.size() ; i++){
            vector<string> temp;
            temp.push_back(strs[i]);
            for(int z = copy.size() -1; z > i ; z--){
                if(copy[i] == copy[z]){
                    temp.push_back(strs[z]);
                    strs.erase(strs.begin()+z);
                    copy.erase(copy.begin()+z);
                }
            }
            ans.push_back(temp);
        }

        
        return ans;
    }
};
