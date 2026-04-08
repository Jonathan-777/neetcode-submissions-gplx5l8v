class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        constexpr int N = 1000;
        bitset<N> visited; // Keeping your bitset!
        
        // Tracks the minimum distance from the MST to each unvisited node
        vector<int> min_dist(n, INT_MAX);
        int ans = 0;
        
        // Start from point 0
        visited = 1;
        int curr_node = 0;
        
        // We need to add exactly n - 1 edges to connect all n points
        for (int edges = 0; edges < n - 1; edges++) {
            int next_node = -1;
            int shortest_edge = INT_MAX;
            
            for (int j = 0; j < n; ++j) {
                if (visited[j] == 0) {
                    // Distance from the NEWEST node in the MST to unvisited node j
                    int dist = abs(points[curr_node][0] - points[j][0]) + 
                               abs(points[curr_node][1] - points[j][1]);
                    
                    // Update min_dist[j] if the new node offers a shorter path
                    if (dist < min_dist[j]) {
                        min_dist[j] = dist;
                    }
                    
                    // Keep track of the absolute closest unvisited node overall
                    if (min_dist[j] < shortest_edge) {
                        shortest_edge = min_dist[j];
                        next_node = j;
                    }
                }
            }
            
            // Add the closest unvisited node to our MST
            visited[next_node] = 1;
            ans += shortest_edge;
            curr_node = next_node; // This node becomes the "newest" node for the next pass
        }
        
        return ans;
    }
};