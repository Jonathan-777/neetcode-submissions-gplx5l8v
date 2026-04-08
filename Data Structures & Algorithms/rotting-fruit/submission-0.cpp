class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();// dynamic
        queue<tuple<int,int,int>> q;
        int ans = 0;

        for(int i = 0; i < m; i++){
            n = grid[i].size();
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i,j,0});
                }
            }
        }

        vector<vector<int>> offsets = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()){
            auto [rows,cols,curr_count] = q.front();  // verry cool/ usefull

            n = grid[rows].size();

            q.pop();

            for(int i = 0; i < 4; i++){
                int r = rows + offsets[i][0];
                int c = cols + offsets[i][1];

                if(r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != 1){
                    continue;
                }
                
                if(curr_count+1 > ans){
                    ans = curr_count+1;
                }
                grid[r][c] = 2;
                q.push({r,c,curr_count+1});
            }
            
        }

        for(int i = 0; i < m; i++){
            n = grid[i].size();
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return ans;

        
    }
};
