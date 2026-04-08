class Trie{
    public:
    unordered_map<char,Trie*> children;
    

    bool endOfWord ;
    Trie(){
        endOfWord = false;
    }

};
class PrefixTree {
public:
    Trie* root = nullptr;
    PrefixTree() {
        root = new Trie();       
    }
    
    void insert(string word) {
        Trie* temp = root;
        for(const char& c : word){
            if(temp->children.find(c) == temp->children.end()){
                temp->children[c] = new Trie();
            }
            temp = temp->children[c];///////////
        }
        temp->endOfWord = true;
        
    }
    
    bool search(string word) {
        Trie* temp = root;
        for(const char& c : word){
            if(temp->children.find(c) == temp->children.end()){
                return false;
            }
            temp = temp->children[c];
        }
        return temp->endOfWord;
        
    }
    
    bool startsWith(string prefix) {
        Trie* temp = root;
        for(const char& c : prefix){
            if(temp->children.find(c) == temp->children.end()){
                return false;
            }
            temp = temp->children[c];
        }
        return true;
        
    }
};
