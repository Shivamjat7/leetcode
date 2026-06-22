class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m =board[0].size();
        vector<vector<int>>ans=board;
        int del[]={0,-1,1};
       for(int i =0;i<n;i++) {
        for(int j=0;j<m;j++){
            int cnt =0;
            for(int k =0;k<3;k++){
                for(int l=0;l<3;l++){
                    if(k==0 && l==0)continue;
                    int r =i+del[k];
                    int c=j+del[l];
                    if(r>=0 && r<n && c>=0 && c<m && board[r][c])cnt++;
                }
            }
            
            if(cnt<2 || cnt>3) ans[i][j]=0;
            if(!board[i][j] && cnt==3) ans[i][j]=1;

        }
       }
       board=ans;
    }
};