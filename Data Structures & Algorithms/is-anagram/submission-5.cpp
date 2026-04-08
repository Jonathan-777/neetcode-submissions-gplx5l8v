class Solution {
public:
    bool isAnagram(string s, string t) {
        multiset<char> ms;
        multiset<char> mt;
        for(auto x: s){
            ms.insert(x);
        }
        for(auto x: t){
            mt.insert(x);
        }
        return ms == mt;
    }
};
