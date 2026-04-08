class TrieTree{
public:
    unordered_map<char,TrieTree*> children;

    string end_of_word ;

    TrieTree(){
        end_of_word = "";
    }

};

class Solution {
public:
    TrieTree* root = nullptr;
    vector<string> ans;


    Solution(){
        root = new TrieTree();
    }

    void populate_trie_helper(vector<string>& words, int i ){
        TrieTree* temp = root;
        
        for(auto c : words[i]){
            if(temp->children.find(c) == temp->children.end()){
                temp->children[c] = new TrieTree();
            }
            temp = temp->children[c];
        }

        temp->end_of_word = words[i];
    }

    void populate_trie(vector<string>& words){
        int size = words.size();
        for(int i = 0 ; i < size; i++){
            populate_trie_helper( words, i);
        }
    }




    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        populate_trie(words);
        ans.clear();

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                trieSearch(board, root, i , j);

            }
        }
        return ans;
        
    }




    void trieSearch(vector<vector<char>>& board,  TrieTree* root,  int i , int j){


        if( i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || root->children.find(board[i][j]) == root->children.end() ) return ;// if out of bounds or not existent return
        TrieTree* temp = root->children[board[i][j]];

        if(  temp->end_of_word != "" ){// if we are at the end of a word return
            ans.push_back(temp->end_of_word);
            temp->end_of_word = "";
            // return ;
        }
        

        char _char = board[i][j];
        board[i][j] = '@';

        trieSearch(board,  temp, i+1, j );
        trieSearch(board,  temp, i-1, j );
        trieSearch(board,  temp, i, j+1 );
        trieSearch(board,  temp, i, j-1 );

        
        board[i][j] = _char;
        return;

    }














   
    
};
