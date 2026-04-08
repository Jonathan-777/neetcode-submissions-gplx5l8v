#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // 1. Count frequencies
        vector<int> counts(26, 0);
        for (char t : tasks) counts[t - 'A']++;

        // 2. Max priority queue to store frequencies
        priority_queue<int> pq;
        for (int f : counts) {
            if (f > 0) pq.push(f);
        }

        int time = 0;
        // Queue stores {remaining_frequency, time_when_available}
        queue<pair<int, int>> cooling;

        while (!pq.empty() || !cooling.empty()) {
            time++;

            // Check if any task is done with cooling
            if (!cooling.empty() && cooling.front().second == time) {
                pq.push(cooling.front().first);
                cooling.pop();
            }

            if (!pq.empty()) {
                int freq = pq.top() - 1; // Execute the most frequent task
                pq.pop();
                
                if (freq > 0) {
                    // Task still has remaining occurrences; add to cooling
                    // It will be available again at time + n + 1
                    cooling.push({freq, time + n + 1});
                }
            }
            // If pq is empty but cooling isn't, the CPU just ticks (idle)
        }

        return time;
    }
};