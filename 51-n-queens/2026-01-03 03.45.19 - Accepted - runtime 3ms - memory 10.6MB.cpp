class Solution {
public:
    vector<vector<string>> res;
    vector<string> board;
    vector<bool> col, diag1, diag2;
    void solve(int r,int n){
        if(r==n){
            res.push_back(board);
            return;
        }
        for(int c =0;c<n;c++){
            if(col[c]|| diag1[r-c+n-1]||diag2[r+c])continue;
            board[r][c]='Q';
            col[c]=diag1[r-c+n-1]=diag2[r+c]=true;
            solve(r+1,n);
            board[r][c]='.';
            col[c]=diag1[r-c+n-1]=diag2[r+c]=false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
       board.assign(n,string(n,'.'));
       col.assign(n,false);
       diag1.assign(2*n-1,false);
       diag2.assign(2*n-1,false);
       solve(0,n);
       return res;
    }
};