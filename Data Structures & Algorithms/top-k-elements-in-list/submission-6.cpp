class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> m;
        multiset<int> k_elements;
        vector<int> ans;
        // vector<unordered_map<int,int>::iterator> iterator_vec;

        for(int i = 0 ; i < nums.size(); i++){
            m[nums[i]]++;
        }
        
        unordered_map<int,int>::iterator it;
        it = m.begin();

        while(it != m.end()){
            if(k_elements.size() < k){
                k_elements.insert((*it).second);

            }else{
                auto temp = k_elements.begin();
                if(*temp < (*it).second){
                    k_elements.erase(temp);
                    k_elements.insert((*it).second);
                }
            }
            it++;
        }

        
        for( it = m.begin(); it != m.end();){
            if(k_elements.empty()){
                break;
            }
            auto l = k_elements.begin();
            auto r = k_elements.rbegin();

            if( (*it).second >= *l && (*it).second <= *r ){
                ans.push_back((*it).first);

                k_elements.erase(k_elements.find((*it).second));
                auto eliminate = it;
                it = next(it);
                m.erase(eliminate);
                continue;
            }
            it++;
        }

        return ans;
        
    }
};
