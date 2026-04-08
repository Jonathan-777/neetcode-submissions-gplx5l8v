class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {// dijkstras

        vector<vector<pair<int,int>>> adj(n+1);

        for(auto vec: times){
            int u = vec[0];
            int v = vec[1];
            int ti = vec[2];

            adj[u].push_back({ti,v}) ;

        }

        vector<int> distance_vec(n+1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0,k});//start node 
        distance_vec[k] = 0;

        while(!pq.empty()){
            pair<int,int> curr = pq.top();
            pq.pop();


            if(distance_vec[curr.second] < curr.first ){
                continue;
            }

            for(auto temp : adj[curr.second]){
                if(curr.first + temp.first < distance_vec[temp.second]){
                    distance_vec[temp.second] = curr.first + temp.first;
                    pq.push({distance_vec[temp.second], temp.second});
                }
            }

        }
        int ans = 0;

        for(int i  = 1; i <= n; i++){
            if(distance_vec[i] == INT_MAX)return -1;
            ans = max(ans, distance_vec[i]);

        }
        return ans;


        
    }
};
