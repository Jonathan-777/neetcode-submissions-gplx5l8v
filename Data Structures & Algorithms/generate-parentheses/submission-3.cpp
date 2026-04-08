class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        current.reserve(n * 2); // Reserve memory upfront to avoid reallocations
        backtrack(result, current, 0, 0, n);
        return result;
    }

private:
    void backtrack(vector<string>& result, string& current, int open, int close, int max) {
        // Base case: if the string is fully formed, add it to our result
        if (current.length() == max * 2) {
            result.push_back(current);
            return;
        }

        // If we haven't used all our open parentheses, we can add one
        if (open < max) {
            current.push_back('(');
            backtrack(result, current, open + 1, close, max);
            current.pop_back(); // Backtrack (undo the move)
        }
        
        // If we have more open than closed parentheses, we can close one
        if (close < open) {
            current.push_back(')');
            backtrack(result, current, open, close + 1, max);
            current.pop_back(); // Backtrack (undo the move)
        }
    }
};