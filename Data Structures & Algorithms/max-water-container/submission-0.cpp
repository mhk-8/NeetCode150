class Solution {
public:
    int maxArea(vector<int>& heights) {
        int mostwater =0;
        for(int i=0;i<heights.size()-1;i++){
            int temp =0;
            for(int j=i+1; j<heights.size(); j++){
                if(heights[i]<= heights[j]){
                    temp = max(temp, (j-i)*(heights[i]));
                }
                else{
                    temp = max(temp, (j-i)*(heights[j]));
                }
                
            }
            mostwater = max(mostwater,temp);
        }
        return mostwater;
    }
};
