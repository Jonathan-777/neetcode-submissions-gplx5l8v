class Solution {
public:
    int countSubstrings(string s) {

        unordered_set<char> my_set;
        int ans = 0; 
        queue<size_t> q;

        auto palindrome_check = [&](const int& l, const int& r){
            // one letter can close multiple palindromes
            string b = "";
            for(int i = r; i >= l ; i--){
                b += s[i];
            }
            string a(s.begin() + l , s.begin() + r+1);
            return a == b;

            
        };


        for(int i = 0 ; i < s.size(); ++i){
            ++ans;
            if(!my_set.insert(s[i]).second){
                // we have seen this letter before
                size_t temp = i;
                temp = s.rfind(s[i], i-1);
                while(  temp != string::npos){
                    q.push(temp);
                    if(temp == 0)break;
                    temp = s.rfind(s[i], temp-1);

                }
                while(!q.empty()){
                    int l = (int)q.front();
                    if(palindrome_check(l,i)){
                        ++ans;
                    }
                    q.pop();
                }
                
                
            }
        }
        return ans;
    }
};
