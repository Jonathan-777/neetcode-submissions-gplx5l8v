class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> res(n + 1);
        res[0] = {""};

        for (int k = 0; k <= n; ++k) {
            for (int i = 0; i < k; ++i) {
                for (const string& left : res[i]) {
                    for (const string& right : res[k - i - 1]) {
                        res[k].push_back("(" + left + ")" + right);
                    }
                }
            }
        }

        vector<string> ans = res[n];
        // cout << res.size() << " and ans size is : " << res[n].size();

        return ans;
    }
};