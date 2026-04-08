class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans = 0;
        vector<int> occurance_arr(26,0);
        priority_queue<pair<int,char>> pq;
        for(char x : tasks){// populate count arr
            occurance_arr[x - 'A']++;
        }

        for(int i = 0; i < occurance_arr.size(); i++){
            int x = occurance_arr[i];
            if(x > 0){  // populate priority queue
                pq.push({x,'A' + i});
            }
        }
        queue<pair<char,int>> q;  // letter , curr ans
        
        char curr;

        
        while( !q.empty() || !pq.empty() ){
            ans++;

            if(!pq.empty()){
                occurance_arr[pq.top().second - 'A']--;

                if(occurance_arr[pq.top().second - 'A'] > 0){
                    cout << pq.size();
                        q.push({pq.top().second, ans + n});
                }
                pq.pop();
            }
            
            

            while(!q.empty() && q.front().second == ans){
                cout << "HELLO";
                pq.push({occurance_arr[q.front().first - 'A'] , q.front().first, });
                q.pop();

            }


        }

        return ans;
    }
};
