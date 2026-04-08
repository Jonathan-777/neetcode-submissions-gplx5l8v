class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int size = points.size();
        if (size <= k )return points;
        set< pair<double, pair<int,int> > > s;

        while(!points.empty()){
           double x = points[points.size() - 1][0];
           double y = points[points.size() - 1][1];
           double x0 = 0.0;
           double y0 = 0.0;
           double temp = sqrt(pow( abs(x0 - x),2.0  )  + pow(abs(y0 - y), 2.0) );

           s.insert({temp,{static_cast<int>(x),(int)y}});
            points.pop_back();
        }

        auto it = s.begin();
        while(it != s.end() && k > 0){
            points.push_back({(*it).second.first , (*it).second.second});
            it = next(it);
            k--;
        }

        return points;
    }
};
