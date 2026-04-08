class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(auto &x : strs){
            res = res + x + '`';
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string temp = "";
        for(auto &x : s){
            if(x != '`'){
                temp = temp + x;
            }else {
                ans.push_back(temp); 
                temp = "";
            }

        }
      return ans;
    }
};
