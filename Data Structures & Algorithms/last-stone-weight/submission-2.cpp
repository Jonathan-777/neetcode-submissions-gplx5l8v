class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {// multiset or PRIORITY QUEUE
        multiset<int> ms;
        for(auto x : stones){
            ms.insert(x);
        }

        while(ms.size() > 1){
            auto it = ms.rbegin();
            auto it_smaller = next(it);
            // multiset takes care of size order
            int newItem = abs(*it - *it_smaller);
            ms.erase(prev(it_smaller.base()));
            ms.erase(prev(it.base()));
            
            ms.insert(newItem);
        }
        return *ms.rbegin();
    }
};
