class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n=bottomLeft.size();
        long long maxArea=0;
        for(int i=0;i<n;i++){
            int x1=bottomLeft[i][0];
            int y1=bottomLeft[i][1];
            int x2=topRight[i][0];
            int y2=topRight[i][1];
            for(int j=0;j<n;j++){
                if(i==j)continue;
            int a1=bottomLeft[j][0];
            int b1=bottomLeft[j][1];
            int a2=topRight[j][0];
            int b2=topRight[j][1];
            
            int left = max(a1,x1);
            int right= min(x2,a2);
            int top= min(y2,b2);
            int bottom = max(y1,b1);
            if(left<=right && bottom<=top){
                int len = min(right-left,top-bottom);
                long long area = 1LL*len*len;
                maxArea =max(maxArea,area) ;
            }
            }
        }
        return maxArea;
    }
};