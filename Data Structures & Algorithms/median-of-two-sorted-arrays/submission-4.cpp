using set_build = set<int>;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        set_build s;


        for(auto x: nums1){
            s.insert(x);
        }
        for(auto x: nums2){
            s.insert(x);
        }
        int size = s.size();
        auto it = s.begin();

        double ans = 0.0;

        auto handle_even = [&](){
            auto it_2 = next(it , (size / 2));
            it = prev(it_2);
            return (*it + *it_2) / 2.0;
        };
        // double even = handle_even();

        return (size % 2 == 0)?  handle_even() : *next(it , size/2.0);


        
        
    }
};
