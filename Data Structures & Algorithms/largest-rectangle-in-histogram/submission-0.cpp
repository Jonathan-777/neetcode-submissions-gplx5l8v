class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {




        auto find_area = [&heights](int i){
            if(heights[i] == 0) return 0;
            auto itBack = heights.begin() + i;
            auto itForward = heights.begin() + i;
            int candidateArea = 0;

            if(i > 0 && i < heights.size()-1){
                // all elements except last and first
                itForward++;
                bool flag = false;
                while(!flag && *itBack >= heights[i]){
                    candidateArea += heights[i];
                    
                    if(itBack == heights.begin()){
                        flag = true;
                    }
                    itBack--;
                }

                while(itForward != heights.end() && *itForward >= heights[i]){
                    candidateArea += heights[i];
                    itForward++;
                }



            }else if( i == 0){//first
                while(itForward != heights.end() && *itForward >= heights[i]){
                    candidateArea += heights[i];
                    itForward++;
                }

            }else{//last
                bool flag = false;

                while(!flag && *itBack >= heights[i]){
                    candidateArea += heights[i];
                    
                    if(itBack == heights.begin()){
                        flag = true;
                    }
                    itBack--;
                }

            }


            return candidateArea;
        };

        int best = 0;

        for(int i = 0; i < heights.size(); i++){
            best = max(best,find_area(i));
        }

        return best;
        
    }
};
