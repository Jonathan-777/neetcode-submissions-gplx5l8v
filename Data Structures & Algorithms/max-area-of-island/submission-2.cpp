class Solution {
public:
    int max_count  = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        max_count = 0;
        int size = grid.size();
        int curr = 0;

        for(int i = 0 ; i < size ; i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    
                    maxAreaOfIsland_helper(grid, curr, i, j);
                    curr = 0;
                }
            }
        }
        return max_count;
    }

    void maxAreaOfIsland_helper(vector<vector<int>>& grid, int& count, int i , int j){
        
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] != 1){
            return;
        }
            
        grid[i][j] = 2;

        
        count = count + 1;

        if((count ) > max_count){
            max_count = count;
        }

        maxAreaOfIsland_helper(grid, count , i-1 , j );
        maxAreaOfIsland_helper(grid, count , i+1 , j );
        maxAreaOfIsland_helper(grid, count , i , j-1 );
        maxAreaOfIsland_helper(grid, count , i , j+1 );

        return;



    }

};
