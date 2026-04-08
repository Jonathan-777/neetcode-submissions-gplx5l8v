#include<array>

class Solution {
public:
    static constexpr array<array<int, 2>, 4> offsets = {{{{ -1, 0 }}, {{ 1, 0 }}, {{ 0, -1 }}, {{ 0, 1 }}}};

    void solve(vector<vector<char>>& board) {
        int height = board.size();
        int width = board[0].size();

        queue<pair<int,int>>q;
        vector<vector<bool>> valid_o(height,vector<bool>(width,false));

        for(int i = 0; i < height;i++){
            if(board[i][width-1] == 'O'){
                q.emplace(i,width-1);
            }
            if(board[i][0] == 'O'){
                q.emplace(i,0);
            }
        }
        for(int i = 0; i < width; i++){
            if(board[0][i] == 'O'){
                q.emplace(0,i);
            }
            if(board[height-1][i] == 'O'){
                q.emplace(height-1,i);
            }
        }

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            if(!valid_o[i][j]){
                solve_helper(board, valid_o, i, j);
            }

        }


        for(int i = 0 ; i < height; i++){
            for(int j = 0; j < width; j++){
                if(valid_o[i][j] == false){
                    board[i][j] = 'X';
                }
            }
        }
        
    }
    void solve_helper(vector<vector<char>>& board, vector<vector<bool>>& valid_o, int i, int j){
        
        valid_o[i][j] = true;

        for(int z = 0 ; z < 4; z++){
            int row = i + offsets[z][0];
            int col = j + offsets[z][1];

            if(row < board.size() && row >= 0 && col < board[0].size() && col >= 0 && valid_o[row][col] == false && board[row][col] == 'O'){
                cout << row << col << i << j << endl;
                
                solve_helper(board,valid_o,row,col);
            }

        }
    }


};
