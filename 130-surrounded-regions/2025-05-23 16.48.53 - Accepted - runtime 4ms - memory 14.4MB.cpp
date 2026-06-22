class Solution {
private:
    void dfs(pair<int,int> node,vector<vector<char>>& board,vector<vector<bool>> & visited){
        int n=board.size();
        int m=board[0].size();
        int r=node.first;
        int c=node.second;
        visited[r][c]=true;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int row= r+delrow[i];
            int col= c+delcol[i];
            if(row>=0 && row<n && col>=0 && col<m){
                if(board[row][col]=='O' && !visited[row][col]){

                    dfs({row,col},board,visited);
                }
            }
        }
        
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m= board[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
           if(board[i][0]=='O'&& !visited[i][0]) dfs({i,0},board,visited);
           if(board[i][m-1]=='O'&& !visited[i][m-1]) dfs({i,m-1},board,visited);
    
        }
        for(int j=0;j<m;j++){
           if(board[0][j]=='O'&& !visited[0][j]) dfs({0,j},board,visited);
           if(board[n-1][j]=='O'&& !visited[n-1][j]) dfs({n-1,j},board,visited);
            
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !visited[i][j]){
                    board[i][j]='X';
                }
            }
        }
        
    }
};