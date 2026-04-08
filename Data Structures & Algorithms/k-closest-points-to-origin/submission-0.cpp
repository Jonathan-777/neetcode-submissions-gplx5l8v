class Solution {
public:
   // minheap
   struct minHeapHelper{
        bool operator()(const pair<double,pair<int,int>>& a, const pair<double,pair<int,int>>& b){
            return a.first > b.first;
        }
   };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
            priority_queue<pair<double,pair<int,int>> , vector<pair<double,pair<int,int>>>, minHeapHelper> pq;

            vector<vector<int>> ans;

            for(int i = 0; i < points.size(); i++){
                double x = ( points[i][0]  );
                double y = ( points[i][1]  );
                double distance = sqrt( x*x + y*y );

                pq.push({distance,{points[i][0], points[i][1]}});
                
            }

            for(int i = 0; i < k; i++){
                pair<double,pair<int,int>> temp;
                temp = pq.top();
                pq.pop();
                ans.push_back({temp.second.first, temp.second.second});
            }


        return ans;
        
    }
};
