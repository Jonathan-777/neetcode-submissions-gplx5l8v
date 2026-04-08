#include <vector>
#include <algorithm>

class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;

        // Pair up position and speed
        std::vector<std::pair<int, int>> cars(n);
        for (int i = 0; i < n; i++) {
            cars[i] = {position[i], speed[i]};
        }

        // Sort cars by position descending (closest to target first)
        std::sort(cars.rbegin(), cars.rend());

        int fleets = 0;
        double slowest_time = 0.0;

        for (int i = 0; i < n; i++) {
            // Calculate time to reach target as a double
            double time = (double)(target - cars[i].first) / cars[i].second;

            // If this car's time is strictly greater than the fleet ahead of it,
            // it cannot catch up. It forms a completely new fleet.
            if (time > slowest_time) {
                fleets++;
                slowest_time = time;
            }
            // Otherwise, it catches up and joins the existing fleet (no fleets++).
        }

        return fleets;
    }
};