class Solution {
public:
    bool isPalindrome(string s) {
        // solution must be O(n), Best solutions ONLY

        transform(s.begin(), s.end(), s.begin(),[](unsigned char c){
            return tolower(c);
        });

        int l = 0; 
        int r = s.size()-1;

        while(l <= r){
            if(!isalnum(s[l])){
                l++;
                continue;
            }
            if(!isalnum(s[r])){
                r--;
                continue;
            }
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }

        return true;
        
    }
};
