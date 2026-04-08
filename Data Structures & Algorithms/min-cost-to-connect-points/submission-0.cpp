class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {// positive distances only... Prims algorithm
        // algorithm itelf is easy but avoiding repeat calculations is challenging





        int n = points.size();

        

       constexpr int N = 1000;

        bitset<N> visited;

        visited.set();//sets all to 1 initially
        visited <<= (n);



        visited[0] = 1;

        vector<vector<int>> adj(n,vector<int>(n, INT_MAX));

        int ans = 0;

        
        

        while(!visited.all()){

            pair<int,int> curr;
            int shortest_edge = INT_MAX;
            int set_to_visted =-1;

            for(int i = 0 ; i < n; i++){
                if(visited[i] == 0 )continue;
                curr = {points[i][0], points[i][1]};

                for(int j = 0; j < n ; j++){
                    if(visited[j] == 1)continue;
                    int candidate = INT_MAX;

                    if(adj[i][j] == INT_MAX){// distance from any 2 points will always be the same

                        candidate = abs(curr.first - points[j][0]) + abs(curr.second - points[j][1]);

                        if(adj[i][j] > candidate){
                            adj[i][j] = candidate;
                        }
                    }else{
                        candidate = adj[i][j];

                    }


                    if(shortest_edge > candidate){
                        shortest_edge = candidate;
                        set_to_visted = j;
                    }

                    
                }
            }

            visited[set_to_visted] = 1;
            ans += shortest_edge;

        }


        return ans;

        
    }
};
