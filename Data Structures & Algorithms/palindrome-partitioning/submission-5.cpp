class Solution {
    vector<vector<bool>> dp;
public:
    vector<vector<string>> partition(string s) {
        int size = s.length();
        dp.resize(size, vector<bool>(size));// initializes to 'false' by default

        for (int len = 1; len <= size; len++) {
            for (int i = 0; i + len - 1 < size ; i++) {// the inner nested loop checks all candidate substrings. for (int i = 0; i <= (size - l) ; i++) also works

                dp[i][i + len - 1]  = (  (s[i] == s[i + len - 1] )     &&    // straight forward check on s. before the equal sign is the beauty of this code.
                                       (len <= 2 || dp[i + 1][i + len - 2])   // key line as well

                                    );
            }
        }

        vector<vector<string>> res;
        vector<string> part;
        dfs(0, s, part, res);
        return res;
    }

private:
    void dfs(int i, const string& s, vector<string>& part, vector<vector<string>>& res) {// easy part
        if (i >= s.length()) {
            res.push_back(part);
            return;
        }
        for (int j = i; j < s.length(); j++) {
            if (dp[i][j]) {
                part.push_back(s.substr(i, j - i + 1));
                dfs(j + 1, s, part, res);
                part.pop_back();
            }
        }
    }
};