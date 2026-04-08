class Solution {
public:
    bool isValid(string s) {
        if(s.size() < 2)return false;
        stack<char> parentheses;
        bool flag = false;
        

        auto check_parentheses = [&flag,&parentheses](char c){
            switch(c){
                case '[': parentheses.push(']');flag = true;break;
                case '(': parentheses.push(')');flag = true;break;
                case '{': parentheses.push('}');flag = true;break;
                default: 
                if(!parentheses.empty() && parentheses.top() != c){
                    cout << "char is  " << c <<  " parentheses.top() thinks its " << parentheses.top() << endl;
                     return false;
                }else if(!parentheses.empty()){
                    parentheses.pop();
                }else{
                        return false;
                }
            }
            return true;
        };
        check_parentheses(s[0]);
        if(flag == false)return false;

        for(int i = 1; i < s.size(); i++){
            if(!check_parentheses(s[i]))return false;
        }
        if(flag == false)return false;
        return parentheses.empty();
        
    }
};
