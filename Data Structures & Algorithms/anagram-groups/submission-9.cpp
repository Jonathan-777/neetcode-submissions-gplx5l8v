class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {// what is the most efficient way to solve? SOLUTION:   commutative hash function (using prime numbers that represent aphabetical letters)
    // because of the high probablity of getting large numbers we cannot use the prime commutative hash function, instead I will use a frequency based polynomial rolling hash
    // instead of multiplying primes we count character frequencies and map them to a fixed size hash
        unordered_map<size_t, vector<string>> groups;
        
        for (const string& s : strs) {
            groups[computeHash(s)].push_back(s);
        }
        
        vector<vector<string>> result;
        for (auto& entry : groups) {
            result.push_back(move(entry.second));
        }
        return result;
        
    }

    private:
  
    size_t computeHash(const string& s) {
        
        int count[26] = {0};
        for (char c : s) count[c - 'a']++;
        
        
        size_t h = 0;
        for (int i = 0; i < 26; i++) {
            
            h ^= hash<int>{}(count[i]) + 2654435769 + (h << 6) + (h >> 2);   // this is the only challenging part
        }
        return h;
    }
};
