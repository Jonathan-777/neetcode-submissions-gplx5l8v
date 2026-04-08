#include <ranges>
class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;// rows, cols

        for(int i = 0; i < m; i++){
            // for( int j = 0; j < n; j++){
            //     if(grid[i][j] == 0){
            //         q.push({i,j});
            //     }
            // }

            auto zero_indexes = views::iota(0,n)
                              | views::filter([&](int j){
                                return grid[i][j] == 0;
                              });
            for(int j : zero_indexes){
                q.push({i,j});
            }

        }

        vector<vector<int>> offsets = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        while(!q.empty()){
            int rows = q.front().first;
            int cols = q.front().second;
            q.pop();

            for( int i = 0 ; i < 4; i++){
                int r = rows + offsets[i][0];
                int c = cols + offsets[i][1];

                if(r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != INT_MAX){
                    continue;
                }
                grid[r][c] = grid[rows][cols] + 1;
                q.push({r,c});
                
            }


        }


        
    }
};
