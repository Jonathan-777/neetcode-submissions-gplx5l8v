class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear();
        sort(candidates.begin(), candidates.end());
        dfs(0, 0, target, {}, candidates);
        return res;
    }

private:
    void dfs(int idx, int cur, int target, vector<int> path, vector<int>& candidates) {
        if (cur == target) {
            res.push_back(path); // inserts sum of items that adds to target
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i] == candidates[i - 1]) continue;
            if (cur + candidates[i] > target) break;  // no more recursion

            path.push_back(candidates[i]);
            dfs(i + 1, cur + candidates[i], target, path, candidates);// call recursively on (each) candidate as starting point,this is the key to avoiding duplicates, the key on "how" is the i value
            path.pop_back();
        }
    }
};
