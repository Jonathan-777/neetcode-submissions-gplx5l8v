class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
         multiset<int> ms;
         for(int stone : stones){
            ms.insert(stone);
         }

         while(ms.size() > 1){

            int heaviest = *ms.rbegin();
            ms.erase(prev(ms.end()));
            int heavy = *ms.rbegin();
            ms.erase(prev(ms.end()));
            int difference = abs(heavy - heaviest);
            if(difference == 0){
                continue;
            }else{
                ms.insert(difference);
            }
         }

         return (ms.empty()) ? 0 : *ms.rbegin();
    }
};
