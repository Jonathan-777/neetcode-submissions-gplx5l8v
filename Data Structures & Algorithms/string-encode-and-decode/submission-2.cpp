class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";

        for(auto &x : strs){
            s  = s + x + '`';
        }
        return s;
    }



    vector<string> decode(string s) {
        vector<string> ans;
        string temp = "";
        for(auto &x : s){
            
            if(x == '`'){
                ans.push_back(temp);
                temp = "";
            }else{
                temp += x;
            }
        }
        return ans;

    }
};
