class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m= mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> distance(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }else vis[i][j]=0;
            }
        }
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int dist= q.front().second;
            q.pop();
            distance[r][c]=dist;
            for(int i=0;i<4;i++){
                int row=r+drow[i];
                int col=c+dcol[i];
                if(row>=0 && row<n && col>=0 && col<m && vis[row][col]==0){
                    vis[row][col]=1;
                    q.push({{row,col},dist+1});
                }
            }
        }
        return distance;
        
    }
};