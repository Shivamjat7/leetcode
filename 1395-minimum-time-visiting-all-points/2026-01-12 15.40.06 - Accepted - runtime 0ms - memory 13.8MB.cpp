class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int cnt =0;
        for(int i=0;i<points.size()-1;i++){
            int x =points [i+1][0]-points[i][0];
            int y = points[i+1][1]-points[i][1];
            cnt+=max(abs(x),abs(y));
        }
        return cnt;
    }
};