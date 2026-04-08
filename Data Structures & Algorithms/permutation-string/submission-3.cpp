class Solution {
public:
    bool checkInclusion(string pattern, string text) {
        // no sorting
        // using sliding window only

// just the size of the strings
        int patternLength = pattern.size(), textLength = text.size();
// edge cases
        if(patternLength > textLength) return false;
        if(patternLength == 0) return true;

// main logic
// we will use a simple array not a hashmap

//initialize arr's with all values 0,
    int patternFrequency[26] = {0}, windowFrequency[26] = {0};

// the index for each char's frequency in the pattern is (c - 'a')
    for(char c: pattern)patternFrequency[c - 'a']++;
// same thing as the last arr but using the non-cool for loop, fills our windows size with the first nth elements in text
    for(int i = 0; i < patternLength; i++) windowFrequency[text[i] - 'a']++;

    auto matches = [&](){// if frequencies match,then we have a permutation. n = 26
        for(int i = 0; i < 26; i++){
            if(patternFrequency[i] != windowFrequency[i]) return false;
        }
        return true;
    };


    int i = 0;
    int j = patternLength-1;
    bool ans = false;

    while(j < textLength ){
        ans = matches();
        if(ans)return true;
        windowFrequency[text[i] - 'a']--;
        i++;
        j++;
        windowFrequency[text[j] - 'a']++;
    }

    return ans;






        
    }
};
