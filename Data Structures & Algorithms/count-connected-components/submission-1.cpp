class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_set<int> s;
        if(n <= 1 )return 1;

        vector<vector<int>> adj(n);//0 <= aᵢ <= bᵢ < n

        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> unvisited;
        unordered_set<int> visited;
        for(int i = 0; i < n; i++){
            unvisited.insert(i);
        }
        int ans = 0;

        while(!unvisited.empty()){
            int curr = *unvisited.begin();
            unvisited.erase(unvisited.begin());
            ans++;
            visited.insert(curr);
            queue<int> q;
            q.push(curr);

            while(!q.empty()){
                    for(auto v : adj[curr]){
                        
                        if(!visited.contains(v)){
                            q.push(v);
                            unvisited.erase(v);
                            visited.insert(v);
                        }
                    
                    }
                    q.pop();
                    if(!q.empty())curr = q.front();
            }



        }


        return ans;

    }
};
