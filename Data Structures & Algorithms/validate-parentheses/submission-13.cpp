class Solution {
public:
    bool isValid(string str) {
        int size = str.size();
        stack<char> s;

        auto parentheses_check = [&](const char& c){

            switch (c){

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
                    if(s.empty())return false;
                    char temp = s.top();
                    if(s.top() != c){
                        return false;
                    }
                    s.pop();
            }
            return true;
        };
        
        for(auto &x: str){
            if(parentheses_check(x) == false){
                return false;
            }
        }
        return s.empty();
    }
};
