#include <ranges>
class Solution {
public:
    unordered_set<int> visited_count;

    bool validTree(int n, vector<vector<int>>& edges) {// undirected graph cycle finder*****
    // to be true 1. all nodes must be connected to eachother in some way 2. any node can be a be a root 3. no cycles 4. |edges| = n -1 strictly
    // if we traverse all nodes and our count of visited is equal to n-1 then return true since its mathematically imossible to have a cycle after we check point 4.
        if(edges.size() == 0){
            return true;
        }
        if( edges.size() != n-1){
            return false;
        }
        

        vector<vector<int>> adj(n);
        
        for(auto& v : edges){// add both ways, ends up with more checks
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);

        }
        queue<int> q;
        q.push(0);
        unordered_set<int> seen;
        seen.insert(q.front());

        while(!q.empty()){
            int curr =  q.front();
            q.pop();
            

            for(auto v : adj[curr] ){
                if(!seen.contains(v)){
                    q.push(v);
                }
                seen.insert(v);
                
            }
        }

        return seen.size() == n;

    }


};
