class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> vec(26,0);
        string rS = "";
        for(auto it = s.rbegin(); it != s.rend(); ++it){
            char c = tolower(*it);
            if( (c <= '9' && c >= '0') || ('a' <= c && 'z' >= c)){
                *it = c;
                rS.push_back(c);
            }
            

        }
        s.erase(remove_if(s.begin(),s.end(), [](char c){
            return !isalpha(c);
        }),s.end());

        cout << s << '\n' << rS;

        return s == rS;
    }
};
