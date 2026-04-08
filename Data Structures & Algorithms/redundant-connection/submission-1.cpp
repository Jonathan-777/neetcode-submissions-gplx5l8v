class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> dsu(n+1);

        iota(dsu.begin(), dsu.end(), 0);

        auto path_compression = [&](int node){

            while(node != dsu[node]){
                node = dsu[node] = dsu[dsu[node]];
            }
            return node;
        };


        for(auto &edge : edges){
            int a = path_compression(edge[0]);
            int b = path_compression(edge[1]);
            cout << a << b;
            if(a == b){
                return edge;
            }
            dsu[a] = b;
        }
        return {};
    }
};
