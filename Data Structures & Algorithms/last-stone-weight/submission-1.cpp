class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> pq;

        for(auto x : stones){
            pq.push(x);
        }

        while(pq.size() > 1){
            int biggest = pq.top();
            pq.pop();
            int secondBiggest = pq.top();
            pq.pop();

            if(biggest == secondBiggest){
                biggest = 0;
                
            }else if(biggest > secondBiggest){
                biggest = biggest - secondBiggest;
            }
            pq.push(biggest);
        }
        return pq.top();
    }
};
