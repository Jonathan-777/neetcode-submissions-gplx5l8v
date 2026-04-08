#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

// 1. The Global Arena for our custom allocator
const int ARENA_SIZE = 500000;
char arena_buffer[ARENA_SIZE];
size_t arena_offset = 0;

// 2. The Custom Allocator Definition
template <typename T>
struct BumpAlloc {
    using value_type = T;
    BumpAlloc() = default;
    
    template <class U> 
    constexpr BumpAlloc(const BumpAlloc<U>&) noexcept {}
    
    T* allocate(std::size_t n) {
        size_t bytes = n * sizeof(T);
        void* ptr = &arena_buffer[arena_offset];
        arena_offset += bytes;
        return static_cast<T*>(ptr);
    }
    
    void deallocate(T* p, std::size_t n) noexcept {
        // Memory is "freed" when arena_offset resets
    }
};

class Solution {
    // 3. The Alias Templates to inject the allocator
    using MyTuple = tuple<int, int, int>;
    using MyDeque = deque<MyTuple, BumpAlloc<MyTuple>>;
    using MyQueue = queue<MyTuple, MyDeque>;

public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Reset our custom allocator's memory pool for each test case
        arena_offset = 0;

        int m = grid.size();
        int n = grid.size();// 

        // 4. Use the custom queue instead of the standard one
        MyQueue q;
        int ans = 0;

        for(int i = 0; i < m; i++){
            n = grid[i].size();
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i,j,0});
                }
            }
        }

        int offsets[][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()){
            auto [rows,cols,curr_count] = q.front();  // verry cool/ usefull

            n = grid[rows].size();

            q.pop();

            for(int i = 0; i < 4; i++){
                int r = rows + offsets[i][0];
                int c = cols + offsets[i][1];

                if(r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != 1){
                    continue;
                }
                
                if(curr_count+1 > ans){
                    ans = curr_count+1;
                }
                grid[r][c] = 2;
                q.push({r,c,curr_count+1});
            }
            
        }

        for(int i = 0; i < m; i++){
            n = grid[i].size();
            // for(int j = 0; j < n; j++){
            //     if(grid[i][j] == 1){
            //         return -1;
            //     }
            // }

            auto it = find_if(grid[i].begin(),grid[i].end(),[](int n ){
                return n == 1;
            } );
            if(*it == 1)return -1;
        }
        return ans;
    }
};