class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

       bool ans = false;

        for(int i = 0; i < board.size(); i++){
            for(int z = 0; z < board[i].size(); z++){
                if(board[i][z] == word[0]){
                    if( exist_helper(board,word,word.begin(),i,z))return true;
                    
                }
            }
        }
        return ans;
    }

    bool exist_helper(vector<vector<char>>& board, string& word, string::iterator it, int i, int j){
        if(it == word.end()){
            return true;
        }
        
        if(i < 0 ||  i >= board.size() || j < 0 || j >= board[i].size()  || board[i][j] != *it){
            return false;
        }
        
        char temp = board[i][j];
        board[i][j] = '@';

        it++;


        bool ans = (
            exist_helper(board,word,it ,i+1,  j)   ||
            exist_helper(board,word,it ,i,    j+1) ||
            exist_helper(board,word,it ,i-1,  j)   ||
            exist_helper(board,word,it ,i,    j-1) 
        );
        board[i][j] = temp;

        return ans;
    }
};
