class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_multiset<char> first;
        unordered_multiset<char> second;

        for(auto x: s){
            first.insert(x);
        }
        for(auto x: t){
            second.insert(x);
        }
        return (first == second)? true : false;
        
    }
};
