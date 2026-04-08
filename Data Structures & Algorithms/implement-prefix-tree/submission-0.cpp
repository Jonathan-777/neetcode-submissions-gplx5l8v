
class TrieNode {
public:
    unordered_map<char, TrieNode*> children; // Your hashmap idea!
    bool isEndOfWord; // Crucial for distinguishing prefixes from full words

    TrieNode() {
        isEndOfWord = false;
    }
};

class PrefixTree {
private:
    TrieNode* root = nullptr;

public:
    PrefixTree() {
        root = new TrieNode(); // The root represents the empty starting point
    }
    
    void insert(string word) {
        TrieNode* current = root;
        
        for (char c : word) {
            // If the letter doesn't exist in the current node's map, add it
            if (current->children.find(c) == current->children.end()) {
                current->children[c] = new TrieNode();
            }
            // Move down the tree
            current = current->children[c];
        }
        // Mark the very last node as the end of a complete word
        current->isEndOfWord = true; 
    }
    
    bool search(string word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                return false; // The path broke, word doesn't exist
            }
            current = current->children[c];
        }
        // Path exists, but is it a complete word?
        return current->isEndOfWord; 
    }
    
    bool startsWith(string prefix) {
        TrieNode* current = root;
        for (char c : prefix) {
            if (current->children.find(c) == current->children.end()) {
                return false; // Prefix path broke
            }
            current = current->children[c];
        }
        // If we survived the loop, the prefix path exists! 
        // We don't care if isEndOfWord is true or not.
        return true; 
    }
};