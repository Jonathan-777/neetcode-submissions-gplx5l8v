class TreeNode{
    public:
    unordered_map<char,TreeNode*> child_nodes;
    bool search_end;

    TreeNode(){
        search_end = false;
    }

};

class WordDictionary {
private :
        TreeNode* root = nullptr;

public:
    WordDictionary() {
         root = new TreeNode();
        
    }
    
    void addWord(string word) {
        TreeNode* temp = root;
        for(char c : word){
            if(temp->child_nodes.find(c) == temp->child_nodes.end()){
                temp->child_nodes[c] = new TreeNode();
            }
            temp = temp->child_nodes[c];
        }
        temp->search_end = true;
        
    }
    
    bool search(string word, TreeNode* start = nullptr) {
        TreeNode* temp = nullptr;
        if(start == nullptr){
             temp = root;
        }else{
            temp = start;
        }

        for(int i = 0; i < word.size(); i++){
        char c = word[i];
        
        // REMOVED: The while loop that skips consecutive dots. 
        // In this problem, ".." means exactly two characters, so we can't skip them!
        
        // REMOVED: if(i == word.size()-1) return true; 
        // We can't return true just because we hit the last letter. We still have to verify it exists!

        if(c == '.'){
            // FIX: If we see a dot, we must branch out and try ALL children
            string remaining_word = word.substr(i + 1); // Get the rest of the word
            
            for(auto const& pair : temp->child_nodes) {
                TreeNode* child = pair.second;
                // Recursively search the rest of the word starting from THIS child
                if(search(remaining_word, child)) {
                    return true; 
                }
            }
            return false; // If we checked all children and none worked, it's a dead end.
            
        } else {
            // Normal character check (Your original logic here was perfect)
            if(temp->child_nodes.find(c) == temp->child_nodes.end()){
                return false;
            }
            temp = temp->child_nodes[c];
        }
    }
        return temp->search_end;

        
    }
};
