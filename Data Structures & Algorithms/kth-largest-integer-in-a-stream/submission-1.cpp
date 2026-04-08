class KthLargest {
public:
    multiset<int> multiS;
    int k_val=0;
    
    KthLargest(int k, vector<int>& nums) : k_val(k) {
        // easy but finding optimal solution is not
        multiS.insert(nums.begin(), nums.end());

    }
    
    int add(int val) {
        multiS.insert(val);
        
        if(k_val <= multiS.size()){
            auto it = next(multiS.rbegin(), k_val-1);
            return *it;
        }

        return -1;

    }
};
