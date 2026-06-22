class Solution {
public:
bool row[9][9] = {}, col[9][9] = {}, box[9][9] = {};

    bool solve(int i,int j,vector<vector<char>>& board){
        if(i==9)return true;
        if(j==9) return solve(i+1,0,board);
        if(board[i][j]!='.') return solve(i,j+1,board);
        int b = (i/3)*3+j/3;
        for(int num=0;num<9;num++){
            if(row[i][num]||col[j][num]||box[b][num])continue;
            board[i][j]= char(num+'1');
            row[i][num] = col[j][num] = box[b][num] = true;
            if(solve(i,j+1,board)) return true;
            board[i][j]='.';
            row[i][num] = col[j][num] = box[b][num] = false;

        }
        return false;
    }
  

    
    void solveSudoku(vector<vector<char>>& board) {
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')continue;
                int num = board[i][j] - '1';
               int boxI = (i/3)*3 + (j/3);
                row[i][num]=col[j][num]=box[boxI][num]=true;
            }
        }
        solve(0,0,board);
        

    }
};