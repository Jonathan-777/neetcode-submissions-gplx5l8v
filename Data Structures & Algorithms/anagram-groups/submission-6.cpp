class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<string> copy(strs);

        for(auto &x: copy){
            sort(x.begin(), x.end());
        }

        
        while(!copy.empty()){
            vector<string> temp;
            int z = 0;
            string tempword = copy[0];
            for(z = 0; z < strs.size();z++){
                if(tempword == copy[z]){
                    temp.push_back(strs[z]);
                    strs.erase(strs.begin() + z);
                    copy.erase(copy.begin() + z);
                    z--;
                }
            }
            // i= z - 1;
            ans.push_back(temp);

        }

        return ans;
    }
};
