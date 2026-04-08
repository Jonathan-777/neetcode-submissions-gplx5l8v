class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,pair<int,int>> m;// pair count, index 

        int size = s.size()-1;
        int l = 0; 
        int ans = 0;

        for(int r = 0; r < size+1; r++){
            m[s[r]].first++;

            if(m[s[r]].first > 1){// duplicate found
                l = max(l, m[s[r]].second + 1);
                m[s[r]].first = 1;
                
            }
            int window_size = r - l + 1;
            m[s[r]].second = r;

            if(window_size > ans){
                ans = window_size;
            }
          


        }
        return ans;
        
    }
};
