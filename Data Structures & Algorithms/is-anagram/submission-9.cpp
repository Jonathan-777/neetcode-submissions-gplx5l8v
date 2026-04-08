class Solution {
public:
    bool isAnagram(string s, string t) {
        

        for(auto x: s){
            auto it = t.find(x);
            if(it == string::npos){
                return  false;
            }
            t.erase(it,1);
        }
        return t.empty();
    }
};
