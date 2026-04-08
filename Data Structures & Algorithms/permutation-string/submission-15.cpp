class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int size = s2.size();
        if(size < s1.size()){
            return false;
        }
        vector<int> vec1(26);
        vector<int> vec2(26);
        for(int i = 0; i < s1.size(); i++){
            vec2[s2[i] - 'a']++;
            vec1[s1[i] - 'a']++;
        }
        int l = 0;

        for(int r = s1.size(); r <size ; r++){
            cout << "here";
            if(vec2 == vec1){
                return true;
            }
            // remove left window char count from vec2
            vec2[s2[l++] - 'a']--;
            // vec2[l]++;
            vec2[s2[r] - 'a']++;



        }

        return vec2 == vec1;
    }
};
