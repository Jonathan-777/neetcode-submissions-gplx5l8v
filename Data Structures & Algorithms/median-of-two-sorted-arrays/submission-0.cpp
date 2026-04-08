class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        double ans = 0;
        for(auto x: nums1){
            s.insert(x);
        }
        for(auto x:nums2){
            s.insert(x);
        }

        if(s.size() % 2 == 0){
            auto middle1 = s.begin();
            advance(middle1, s.size()/2);
            auto middle2 = prev(middle1);
            ans = (*middle1 + *middle2) / 2.0;

        }else{
            auto middle = s.begin();
            advance(middle, s.size() / 2.0);
            ans = *middle;
        }
        return ans;
    }
};
