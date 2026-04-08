#include <iterator>   // for std::distance
#include <algorithm>  // for std::find
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> my_string;
        int counterMax = 0;
        int max = 0;
        auto beginning = s.begin();


        for(int x = 0 ; x < s.size(); x++){
            if(my_string.insert(s[x]).second){
                counterMax++;
                cout << "added " << s[x] << "  counter is "<< counterMax << endl;
                if(max <= counterMax){
                    max = counterMax;
                }
            }else{
                // my_string.erase(x);// del the duplicate
                if(s[x] == s[x-1]){
                    counterMax = 1;
                }else{
                    auto it = find(beginning, s.end(), s[x]);
                    
                    int range = distance(beginning,it)+1;
                    cout << "range is " << range << endl;

                    // counterMax -= range;
                    int temp = counterMax;
                    beginning = beginning + range;
                    cout << "new begin is: " << s[distance(s.begin(),beginning)] << endl;
                    my_string.clear();
                    counterMax =0;
                    for (auto i = beginning; i <= s.begin() + x; i++) {
                    my_string.insert(*i);
                    counterMax++;
                }
                    
                }

            }
        }
        return max;
    }
};
