#include <atomic>
class Solution {
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0},
                                         {0, 1}, {0, -1}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        std::atomic<int> a = 5;
// std::atomic<int> b = a; //this would crash the program. these 2 vars are irrelevant
        int ROWS  {heights.size()}, COLS = heights[0].size();
        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));// whatever cells are true are ans
        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));

        queue<pair<int, int>> pacQueue, atlQueue;

        for (int c = 0; c < COLS; ++c) {
            pacQueue.push({0, c});
            atlQueue.push({ROWS - 1, c}); 
        }
        for (int r = 0; r < ROWS; ++r) {
            pacQueue.push({r, 0});
            atlQueue.push({r, COLS - 1});
        }

        bfs(pacQueue, pac, heights);
        bfs(atlQueue, atl, heights);

        vector<vector<int>> res;

        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (pac[r][c] && atl[r][c]) {
                    res.push_back({r, c});
                }
            }
        }
        return res;
    }

private:
    void bfs(queue<pair<int, int>>& q, vector<vector<bool>>& ocean, vector<vector<int>>& heights) {

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            ocean[r][c] = true;
            for (auto [dr, dc] : directions) {
                int ROW = r + dr, COL = c + dc;

                if (ROW >= 0 && ROW < heights.size() && COL >= 0 && COL < heights[0].size() && !ocean[ROW][COL] && heights[ROW][COL] >= heights[r][c]) {
                    q.push({ROW, COL});
                }
            }
        }

        
    }
};


