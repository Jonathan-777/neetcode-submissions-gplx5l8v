class Solution {
public:
    bool isValid(string st) {
        if(st.size() <= 1)return false;
        stack<char> s;

        auto process_parentheses = [&](const char& c){

            switch(c){
                case '[': s.push(']');
                break;
                case '(': s.push(')');
                break;
                case '{': s.push('}');
                break;
                default :
                    
                    if(s.empty() || s.top() != c ){
                        return false;
                    }else{
                        s.pop();
                    }
            }
            return true;
        };


        bool ans = false;
        for(auto x: st){
            ans = process_parentheses(x);
            if(!ans)return false;
        }
        return s.empty();
    }
};
