class Solution {
public:
    string minWindow(string s, string t) {
        // since we cant optimize everything,  here i try to optimize for time and sacrafice memory if needed
        if(t.size() > s.size()) return "";
        if(t == s) return s;

       unordered_map<char,int> need;// l char , index
    //    using itParam = unordered_map<char,int>::iterator;
       queue<pair<char,int>> q;
        bitset<256> copyT ;  // only checks for existence
       int  tCOUNTS[256] = {0}; // array checks for counts and existence (more overhead that bitset), by a bit
       int total_count_in_tCOUNTS = t.size();  // HELPER for the tcount array

       int range = INT_MAX;
       pair<int,int> ans ={0,0};




        // string copyT = t;



       for(auto x: t){
            tCOUNTS[x]++;
            copyT.set(x);
       }



        int i = 0;

       for(i = 0; i < s.size(); i++){//everything works now just figure out how to check remaning items after totalcount is 0 and i is at the end
        
            // if the char in s is also part of t :
            if(copyT.test(s[i])){
                q.push({s[i], i});
            }

            if(copyT.test(s[i])){
                if(tCOUNTS[s[i]] > 0){
                        // cout << "at index " << i << "   removing '" << s[i] << "': " << tCOUNTS[s[i]] << " -> " << (tCOUNTS[s[i]] - 1)
                        //     << " | total_count_in_tCOUNTS: " << total_count_in_tCOUNTS << " -> " ;
                            

                        
                      total_count_in_tCOUNTS--;
                       cout << (total_count_in_tCOUNTS ) << " at index : "<< i << '\n' ;

                    }
                    tCOUNTS[s[i]]--;
            }



            if(copyT.test(s[i])){
                // shrink copyT O(1) with bitset  (It uses $1/8$ the memory of a bool array)
                // add it to the q  O(1)                                                                          DONE
                // check window size if copyT is empty  O(1)                                                      DONE
                // if window is empty move window and 
                //delete from the q the left O(1)                                                                 DONE          
                // 
                
                
                while(total_count_in_tCOUNTS <= 0){
                    
                    int l = q.front().second;
    
                    // Use the current i to define the length
                    int currentLen = i - l + 1; 
                    if(range > currentLen){
                        range = currentLen;
                        ans = {l, range}; // Store the length directly
                    }

                    if(tCOUNTS[q.front().first] < 0){
                        tCOUNTS[q.front().first]++;

                    }else{
                        total_count_in_tCOUNTS++;
                        tCOUNTS[q.front().first]++;
                        cout << " total count is " << total_count_in_tCOUNTS << " and arr count is " << tCOUNTS[q.front().first] << " -> " << q.front().first << endl;

                    }                    
                    
                    q.pop();


                }
                
            }
       }

       if(total_count_in_tCOUNTS <= 0){
                    
                    int l = q.front().second;
    
    // Use the current i to define the length
                int currentLen = i - l + 1; 
                if(range > currentLen){
                    range = currentLen;
                    ans = {l, range}; // Store the length directly
                }

                    if(tCOUNTS[q.front().first] < 0){
                        tCOUNTS[q.front().first]++;

                    }else{
                        total_count_in_tCOUNTS++;
                        tCOUNTS[q.front().first]++;
                        cout << " total count is " << total_count_in_tCOUNTS << " and arr count is " << tCOUNTS[q.front().first] << " -> " << q.front().first << endl;

                    }                    
                    
                    q.pop();


        }


        if (range == INT_MAX) return ""; // No valid window was ever found
        return s.substr(ans.first, ans.second);

        
    }
};
