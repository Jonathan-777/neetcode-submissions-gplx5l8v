class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }

        vector<int> arr(26,0);
        vector<int> window(26,0);

        for(int i = 0 ; i < s1.size(); i++){
            arr[s1[i] - 'a']++;
            window[s2[i] - 'a']++;
        }

        for(int i = s1.size() ; i < s2.size(); i++ ){

            if(arr == window){
                return true;
            }

            window[s2[i] - 'a']++;
            window[s2[i-s1.size()] - 'a']--;

        }
        return arr == window;
    }
};
