class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {//bellman ford?

        constexpr int INF = 1e9;
        vector<int> airports_price(n,INF);

        airports_price[src] = 0;
  


        for(int edge = 0; edge <= k ; edge++){// kill 2 birds with one stone by using k

            vector<int> temp_v = airports_price;

            for(const auto& flight : flights){
                int u = flight[0];
                int v = flight[1];
                int dist = flight[2];

                if(airports_price[u] != INF && airports_price[u]+dist < temp_v[v]){
                    temp_v[v] = airports_price[u] + dist;
                }

            }
            // skip negative weight check
            airports_price = temp_v;

        }

        return (airports_price[dst] == INF) ? -1 : airports_price[dst];

        
    }
};
