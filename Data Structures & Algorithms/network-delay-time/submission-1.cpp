#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // 1. Build the Adjacency List
        // adj[u] will store pairs of {time_to_reach_v, v}
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& edge : times) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            adj[u].push_back({weight, v});
        }

        // 2. Setup the Min-Heap Priority Queue
        // Stores {current_distance, node}. 
        // greater<pair<int,int>> ensures the smallest distance is always at the top.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // 3. Distance Array
        // Keeps track of the shortest time to reach each node. Initialize to infinity.
        vector<int> dist(n + 1, INT_MAX);

        // 4. Start at node 'k'
        pq.push({0, k});
        dist[k] = 0;  // hardcode the init dist

        // 5. Run Dijkstra's
        while (!pq.empty()) {
            auto [curr_time, u] = pq.top();
            pq.pop();

            // Optimization: If we pulled a stale, longer path from the queue, skip it.
            if (curr_time > dist[u]) continue;

            // Check all neighbors
            for (const auto& [weight, v] : adj[u]) {
                // If the path through 'u' is faster than what we currently know for 'v'
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v}); // Push the new better path to the queue
                }
            }
        }

        // 6. Find the maximum time it took to reach any node
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            // If any node is still at INT_MAX, it means it's unreachable
            if (dist[i] == INT_MAX) return -1; 
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};