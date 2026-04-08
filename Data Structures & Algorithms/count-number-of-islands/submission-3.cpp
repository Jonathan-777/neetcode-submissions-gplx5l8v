class Solution {
public:
    
    int numIslands(vector<vector<char>>& grid) {
        int ans  = 0;
        int size = grid.size();
        bool flag = false;
        for(int i = 0 ;  i < size; i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    numIslands_helper(grid, i , j);
                    ans++;
                }
            }
        }
        return ans;
    }

    void numIslands_helper(vector<vector<char>>& grid,  int i , int j){
        if( i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size()  || grid[i][j] != '1'){
            return;
        }

        // if(grid[i][j] == '1' ){
        //     flag = true;
        // }
        // no need to return 1's after we use them
        grid[i][j] = '@';

        
            numIslands_helper(grid, i+1, j) ;
            numIslands_helper(grid, i-1, j) ;
            numIslands_helper(grid, i, j+1) ;
            numIslands_helper(grid, i, j-1);
       
        return;

    }

};
