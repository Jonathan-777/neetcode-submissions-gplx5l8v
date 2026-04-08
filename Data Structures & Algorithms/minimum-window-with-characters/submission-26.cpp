class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size())return "";
        int l = -1; // l will be starting at first char that matches any char in t
        int r = 0;
        int size = s.size();
        pair<int,int> ans({0,INT_MAX});
        int match_count = 0;
        unordered_map<char,int> t_map;
        unordered_map<char,int> s_map;

        for(auto x : t){
            t_map[x]++;  //occurance map
            s_map[x] = 0;
        }

        auto find_l = [&](){
            l++;
            auto it = s.begin() + l;  // starts iterator at l

            for(it ; it != s.end(); ++it){// go through all of s
                auto mapIt = t_map.find(*it);
                    if(mapIt != t_map.end() ){
                        l = distance(s.begin(), it); 
                        return;
                    }
            }
            // throw runtime_error("reached end of s_map and didnt find the next l");
            return;
        };
        find_l();
        if(l == size) return "";



        auto increase_s_map_and_handles_l = [&](const char& c){  // c is is s[r];
                s_map[c]++;
                if(s_map[c] == t_map[c]){   // handles case where we have reached the required count
                    match_count++;
                }
                
                while(s_map[s[l]] > t_map[s[l]]){ 
                    s_map[s[l]]--;  
                    // Notice how we don't even need to decrement match_count here?
                    // If we only enter this loop when we have a SURPLUS of s[l], 
                    // we will never drop below the required amount!
                    find_l();  
                }

                return;
        };



        for( r  = l ; r < size ; r++){
            int c = s[r];
            auto it = t_map.find(c);
            if(it != t_map.end()){
                // match
                // match_count++;
                increase_s_map_and_handles_l(c);
                

            }

            if(match_count == t_map.size()) {  // use match count
                if( (abs(ans.first - ans.second) + 1)  >  r - l + 1){
                    ans = {l,r};
                }
            }

        }



        if(ans.second == INT_MAX) return ""; // Edge case: no window ever found
        return s.substr(ans.first, abs(ans.second - ans.first )+ 1);

      
        
    }
};
