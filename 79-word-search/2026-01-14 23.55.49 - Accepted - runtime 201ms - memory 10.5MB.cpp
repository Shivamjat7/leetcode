class Solution {
public:
    int n,m;
    int dx[4]={0,-1,0,1};
    int dy[4]={-1,0,1,0};
    bool f(int i,int j,int idx,vector<vector<char>>& board, string &word){
        if(idx==word.size())return true;
        if(i<0 ||i>=n ||j<0 ||j>=m||word[idx]!=board[i][j])return false;
        char temp = board[i][j];
        board[i][j]='$';
        for(int k =0;k<4;k++){
            int r =i+dx[k];
            int c =j+dy[k];
            if (f(r,c,idx+1,board,word))return true;
        }
        board[i][j]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
         n = board.size();
         m = board[0].size();
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(f(i,j,0,board,word))return true;
            }
         }
         return false;
    }
};