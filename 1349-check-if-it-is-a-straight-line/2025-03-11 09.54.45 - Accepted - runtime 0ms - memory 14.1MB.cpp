class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& arr) {
        for(int i=0;i<arr.size()-2;i++){
            if(slope(arr,i) != slope(arr,i+1)){
                return false;
            }
            

        }
        return true;
        
    }
    double slope(vector<vector<int>>& arr,int i){
            double y = (arr[i+1][1]-arr[i][1]);
            double x= (arr[i+1][0]-arr[i][0]);
        
         double res = INT_MAX;
         if(x!=0)  res =y/x;
        return res;
    }
    
};