class Solution {
public:
    bool isPalindrome(string s) {
        queue<char> q;
        int counter = 0;
        if(s.empty())return false;
        for(auto x : s){
            if((x <= 122  && x >= 97 ) ||( x <= 90 && x >= 65) || ( x <= 57 && x >= 48) ){
                q.push(x);
                counter++;
            }else {

            }
            
        }
        // if(counter == 0){
        //     return true;
        // }else if(counter < 2){
        //     return false;
        // }

        for(int i = s.size() ; i >= 0; i--){
            if(!((s[i] <= 122  && s[i] >= 97 ) ||( s[i] <= 90 && s[i] >= 65))){
                continue;
            }else if(static_cast<char>(tolower(static_cast<unsigned char>(s[i])) )  != static_cast<char>(tolower(static_cast<unsigned char>(q.front())) )  ){
                return false;
            }else{
                q.pop();
            }
        }

        return true;
    }
};
