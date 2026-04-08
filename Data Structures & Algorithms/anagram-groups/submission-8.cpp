class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        auto insert_as_unordered_set = [](string s){
            unordered_multiset<char> temp;
            for(auto x : s){
                temp.insert(x);
            }
            return temp;
        };

        while(!strs.empty()){
            unordered_multiset<char> temp = insert_as_unordered_set(strs[0]);
            vector<string> subVec;
            vector<string>::iterator it;
            it = strs.begin();

            while(it != strs.end()){
                unordered_multiset<char> comp = insert_as_unordered_set(*it);
                if(comp == temp){
                    subVec.push_back(*it);
                    *it = move(strs.back());
                    strs.pop_back();
                }else{
                   it =  next(it);
                }

            }
            
            ans.push_back(subVec);

        }

        return ans;
        
    }
};
