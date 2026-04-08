class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int size = nums1.size() + nums2.size();
        if(size == 0)return 0.0;
        int nums1INDEX = 0;
        int nums2INDEX = 0;
        float answ = 0.0;



        while(nums1INDEX < nums1.size() || nums2INDEX < nums2.size()){
            if(nums1INDEX < nums1.size() && nums2INDEX < nums2.size()){
                int temp = (nums1[nums1INDEX] >= nums2[nums2INDEX])? nums2[nums2INDEX++] : nums1[nums1INDEX++];
                ans.push_back(temp);
                
            }else if(nums1INDEX < nums1.size()  && nums2INDEX >= nums2.size() ){
                ans.push_back(nums1[nums1INDEX++]);


            }else if(nums2INDEX < nums2.size() && nums1INDEX >= nums1.size()){
                ans.push_back(nums2[nums2INDEX++]);

            }

        }

            answ = (size % 2 == 0)? ((ans[size/2] + ans[(size/2)-1]) / 2.0 ): ans[(size/2)];
        


        return answ;
        
        
    }
};
