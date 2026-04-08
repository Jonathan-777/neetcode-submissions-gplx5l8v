#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string text, string target) {
        if (target.empty() || target.size() > text.size()) return "";

        // Frequency counts for needed and current window chars
        int requiredCount[128] = {0};
        int windowCount[128] = {0};

        int distinctRequiredChars = 0;
        for (char c : target) {
            if (requiredCount[(unsigned char)c] == 0) {
                distinctRequiredChars++;
            }
            requiredCount[(unsigned char)c]++;
        }

        int formedChars = 0;
        int bestWindowLength = INT_MAX;
        int bestWindowStart = 0;

        // Sliding window [left, right]
        for (int left = 0, right = 0; right < (int)text.size(); ++right) {
            unsigned char currentChar = (unsigned char)text[right];
            windowCount[currentChar]++;

            if (requiredCount[currentChar] > 0 && 
                windowCount[currentChar] == requiredCount[currentChar]) {
                formedChars++;
            }

            // Try shrinking from the left if all requirements are satisfied
            while (formedChars == distinctRequiredChars) {
                if (right - left + 1 < bestWindowLength) {
                    bestWindowLength = right - left + 1;
                    bestWindowStart = left;
                }

                unsigned char leftChar = (unsigned char)text[left++];
                windowCount[leftChar]--;
                if (requiredCount[leftChar] > 0 && 
                    windowCount[leftChar] < requiredCount[leftChar]) {
                    formedChars--;
                }
            }
        }

        return bestWindowLength == INT_MAX ? "" : text.substr(bestWindowStart, bestWindowLength);
    }
};
