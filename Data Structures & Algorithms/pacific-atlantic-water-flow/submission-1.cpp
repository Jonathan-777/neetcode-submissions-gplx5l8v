class Solution {
public:
     vector<vector<int>> offsets = {{-1,0},{1,0}, {0,-1},{0,1}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        queue<pair<int,int>> atlantic_q;
        queue<pair<int,int>> pacific_q;
        int heights_size = heights.size();
        int heights_width = heights[0].size();// rectangular grid always

        vector<vector<bool>> flow_p(heights_size, vector<bool>(heights_width));
        vector<vector<bool>> flow_a(heights_size, vector<bool>(heights_width));
        

        for(int i = 0; i <  heights_size; i++){
            pacific_q.emplace(i,0);
            atlantic_q.emplace(i, heights_width-1);
        }
        for(int i = 0; i < heights_width; i++){
            pacific_q.emplace(0, i);
            atlantic_q.emplace(heights_size - 1, i);
        }

        while(!pacific_q.empty()){
            // queue<pair<int,int>> temp; 
            // temp.push(pacific_q.front);
            flow_p[pacific_q.front().first][pacific_q.front().second] = true;
            
            pacificAtlantic_helper(heights,flow_p, pacific_q.front().first, pacific_q.front().second);
            pacific_q.pop();

        }
        while(!atlantic_q.empty()){
            // queue<pair<int,int>> temp; 
            // temp.push(pacific_q.front);
            flow_a[atlantic_q.front().first][atlantic_q.front().second] = true;
            
            pacificAtlantic_helper(heights,flow_a, atlantic_q.front().first, atlantic_q.front().second);
            atlantic_q.pop();

        }

        vector<vector<int>> ans;

        for(int i = 0 ; i < heights_size; i++){
            for(int j = 0; j < heights_width; j++ ){
                if(flow_a[i][j] == true && flow_p[i][j] == true){
                    ans.push_back({i,j});
                }
            }
        }


        return ans;

        
    }

void pacificAtlantic_helper(vector<vector<int>>& heights, vector<vector<bool>>& flow, int r, int c) {
        flow[r][c] = true;

        for(int i = 0; i < 4; i++){
            int row = r + offsets[i][0];
            int col = c + offsets[i][1];

            
            if (row >= 0 && row < heights.size() && col >= 0 && col < heights[0].size()) {
                
                
                if (!flow[row][col] && heights[row][col] >= heights[r][c]) {
                    pacificAtlantic_helper(heights, flow, row, col);
                }
            }
        }
    }


    
};
