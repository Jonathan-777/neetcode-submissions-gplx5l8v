class Solution {
public:
    vector<string> letterCombinations(string digits) {  // CARTESIAN PRODUCT (NOT COMBINATION)
        if (digits.empty()) return {};

        vector<string> res = {""};// empty string allows this code to work
        vector<string> digitToChar = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "qprs", "tuv", "wxyz"
        };

        for (char digit : digits) {
            vector<string> tmp;
            for (string &curStr : res) {
                for (char c : digitToChar[digit - '0']) {
                    tmp.push_back(curStr + c);
                }
            }
            res = tmp;
        }
        return res;
    }
};