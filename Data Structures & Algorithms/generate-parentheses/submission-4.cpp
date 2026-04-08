class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> ans(n+1);
        ans[0] = {""};

        // nested loops

        for(int i = 0 ; i <= n; i++){
                
            for(int z = 0; z < i; z++ ){
                
                for(string& left : ans[z]){
                    
                    for(string& right : ans[i - z - 1]){
                        ans[i].push_back(left + "(" + right + ")");
                    }

                }
            }

        }

        return ans[ans.size()-1];
        
    }


};
