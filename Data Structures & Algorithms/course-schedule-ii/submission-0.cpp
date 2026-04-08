class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {// directed graph cycle finder*****

        vector<vector<int>> adj(numCourses);
        vector<int>  indegree(numCourses,0);        

        for(auto curr : prerequisites){
            indegree[curr[1]]++;
            adj[curr[0]].push_back(curr[1]);
        }
        vector<int> ans(numCourses);
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }

        }
        int counter = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans[numCourses - counter - 1] = curr;
            counter++;
            
            for(auto temp : adj[curr]){
                
                indegree[temp]--;
                if(indegree[temp] == 0){
                    
                    q.push(temp);
                }
            }

        }
        if (counter != numCourses) {
            return {};
        }

        return ans;

    }
};
