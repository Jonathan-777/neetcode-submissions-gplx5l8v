class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() >  s.size())return "";
        if(t==s)return s;
        // if(t.size() == s.size() && s != t)return "";
        string copyT =t;
        string ans(1001,'a');
        unordered_map<char,int> m;

        for(auto x: t){
            if(s.find(x) == string::npos){
                return "";
            }
        }




        auto find_next_t_char = [&t,&s](string::iterator it){// finds next char that is included in t string
            
            while(it != s.end()){
                if(t.find(*it) != string::npos){
                    return it;
                }
                it++;
            }
            cout << "outside while loop" << endl;
            return it;
        };

        auto itBegin = find_next_t_char(s.begin());
        cout << "start is " << *itBegin << endl;
        for(int i = 0; i < s.size(); i++){
            //todo: removeitemfromcopy1, keepAnIteratorAtStartOfWindow1, createprospectstring1, accountforDuplicatecharsinWindow0

            if(t.find(s[i]) != string::npos){// this removes 1 item from T if it is included in S
                auto removeCharFromCopyT = copyT.find(s[i]);// TEMP iterator from copyT


                if(removeCharFromCopyT != string::npos){

                       copyT.erase(removeCharFromCopyT, 1);



                }else{
                    m[s[i]]++;
                    cout << "incremented map for " << s[i] << endl;
                }



            }else{
                        continue;
            }

                     while(copyT.empty()){  // todo : addTheRemovedCharBackToCopy1, moveBeginIteratorToNextRelevantChar1,  CheckAllWindowWhenEmpty0
                        // we have found all items in t, we are at idx of window +1  (we get the window from s directly)
                        
                        auto itEnd = s.begin() + (i + 1);
                        string prospect(itBegin, itEnd);// create a temp copy of the window


                        // As the left pointer (itBegin) moves forward:                        find for the beggining of window not s[i]
                        char outgoingChar = *itBegin; 
                        auto it = m.find(outgoingChar);

                        if (it != m.end() && it->second > 0) {
                            // This was an "extra" character we stored in the map
                            cout << "Found extra " << outgoingChar << " in map, decrementing." << endl;
                            it->second--;
                        } else {
                            // This was a "required" character, put it back in copyT
                            copyT.push_back(outgoingChar);
                        }




                        itBegin = find_next_t_char(itBegin+1);             // will find the next relevant item in our string  **(automatically cuts off non relevant chars)
                                                        cout << "start is " << *itBegin << " at index " << distance(s.begin(), itBegin) << endl;
                                                         if(ans.size() < 100)cout<< "comparing " << ans << " and " << prospect << endl;
                        if(prospect.size() < ans.size()){
                            ans = prospect;
                        }

                    }



        }
        if(ans == "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") return "";
        return ans;
    }
};
