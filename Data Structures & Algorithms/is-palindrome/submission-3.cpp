class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(remove(s.begin(),s.end(), ' '),s.end());

        
        
        int z = 0;
        while (z < s.size()) {
            if (s[z] >= '0' && s[z] <= '9') { z++; continue; }
            if (s[z] >= 'A' && s[z] <= 'Z') { s[z] += 32; z++; continue; }
            if (s[z] >= 'a' && s[z] <= 'z') { z++; continue; } // keep lowercase
            s.erase(s.begin() + z);
        }


        int i = 0;
        int j = (int)s.size() - 1;
        while( i < j){
            if(s[i] != s[j])return false;
            i++;
            j--;
        }
        return true;
    }
};
