class Solution {
public:
    string minWindow(string s, string t) {//main takaway: dont make a hard problem harder by attempting new tricks while doing it (for now)
        if(t.size() > s.size()) return "";
        if(t == s) return s;

        vector<char*> occurances;
        unordered_map<char,int> m_t, m; 
        pair<int, int> ans = {0, INT_MAX};
        int size = s.size();
        
        // 1. Build the frequency map of required characters
        for(auto x : t){
            m_t[x]++;
        }
        
        // 2. Set 'need' to the number of UNIQUE characters required
        int need = m_t.size(); 
        
        // 3. Filter down to only the relevant characters
        for(int i = 0 ; i < size; i++){
            auto it = m_t.find(s[i]);
            if(it != m_t.end()){
                occurances.push_back(&s[i]);
            }
        }
        
        int l = 0;
        int have = 0;

        for(int r = 0; r < occurances.size(); r++){
            char current_char = *occurances[r];

            m[current_char]++;
            
            // 5. If we just hit the exact required count for this character, we "have" it!
            if(m[current_char] == m_t[current_char]){
                have++;
            }

            char left_char = *occurances[l];
            
            // 6. Shrink the window if we have a surplus of the leftmost character
            while( m[left_char] > m_t[left_char] ){
                m[left_char]--;                  
                l++;
                left_char = *occurances[l];
            }

            // 7. Check if our window is valid in O(1) time
            if(have == need){
               ans = (((occurances[r] - &s[0]) - (occurances[l] - &s[0])) < (ans.second - ans.first) ) ?  pair<int,int>{(occurances[l] - &s[0]),(occurances[r] - &s[0])} : ans;
            }
        }

        if(ans.second == INT_MAX){ return ""; }
        
        return s.substr(ans.first, ans.second - ans.first + 1);
    }
};