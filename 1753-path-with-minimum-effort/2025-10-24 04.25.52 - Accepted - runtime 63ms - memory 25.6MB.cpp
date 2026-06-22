class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> efforts(n,vector<int>(m,1e9));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        pq.push({0,0,0});
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!pq.empty()){
            auto[e,row,col]=pq.top();
            pq.pop();
            if(row==n-1 && col==m-1) return e;
            for(int i =0;i<4;i++){
                int r =row+drow[i];
                int c =col+dcol[i];
                if(r>=0 && r<n && c>=0 && c<m){
                   int newEfforts = max(e, abs(heights[row][col] - heights[r][c]));
                    if(newEfforts<efforts[r][c]){
                        efforts[r][c]=newEfforts;
                        pq.push({newEfforts,r,c});
                        
                    }
                }
            }
        }
return -1;
    }
};