class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        unordered_map<int, string> m;

        for(int i = 0 ; i < size; i++){
                // Find the last occurrence of s[i] in the string
            size_t right_idx = s.rfind(s[i]); 
            
            // Keep looking backwards until our right index meets our left index (i)
            while (right_idx > i) {
                // Extract the substring
                string temp = s.substr(i, right_idx - i + 1);
                
                if (longestPalindrome_helper(temp)) {
                    m[temp.size()] = temp;
                }
                
                // Find the NEXT occurrence of s[i] moving backwards
                // (starting from right_idx - 1)
                right_idx = s.rfind(s[i], right_idx - 1); 
            }
                    
        }
        string ans(1,s[0]);

        for(auto it = m.begin(); it != m.end(); ++it){
            if((*it).first > ans.size()){
                ans = (*it).second;
            }

        }
        return ans;
        
    }
    bool longestPalindrome_helper(string substr){
        string s = "";
        s.reserve(substr.size());

        for(auto c : substr){
            s += tolower(c);// no negative chars
        }
        
        string temp(s.rbegin(),s.rend());
        // string temp = string(s.rbegin(), s.rend());  //  Also works
        return temp == s;
    }
};
