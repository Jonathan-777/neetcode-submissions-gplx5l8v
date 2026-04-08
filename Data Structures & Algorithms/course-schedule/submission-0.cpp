class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);// represents dependencies where index is class and its dependency count

        vector<vector<int>> adj(numCourses);

        for (auto& pre : prerequisites) {
            indegree[pre[1]]++;
            adj[pre[0]].push_back(pre[1]);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {// only push non dependency courses
                q.push(i);
            }
        }

        int finish = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            finish++;
            for (int nei : adj[node]) {
                indegree[nei]--;// subtracts dependency count
                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        return finish == numCourses;
    }
};