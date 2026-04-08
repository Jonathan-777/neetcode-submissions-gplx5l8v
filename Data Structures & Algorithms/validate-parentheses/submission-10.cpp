class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        if(str.size() < 2)return false;

        auto stackManager = [&](char c){
            switch(c){
                case '{':
                    s.push('}');
                    break;
                case '[':
                    s.push(']');
                    break;

                case '(':
                    s.push(')');
                    break;
                
                default:
                    if (s.empty() || c != s.top()){
                        return false;
                    }
                    s.pop();
                    
            }
            return true;
        };

        bool ans = false;
        for(auto c: str){
           ans = stackManager(c);
           if(!ans)return false;
        }

        return s.empty();
        
    }
};
