class Solution {
public:
    vector<bool> col,diag1,diag2;
    int cnt=0;
    void f(int i,int n){
        if(i==n){
            cnt++;
            return ;
        }
        for(int j=0;j<n;j++){
        if(col[j]||diag1[i+j]||diag2[i-j+n-1]) continue;
       
        col[j]=diag1[i+j]=diag2[i-j+n-1]=true;
        f(i+1,n);
        col[j]=diag1[i+j]=diag2[i-j+n-1]=false;
        }
    }
    int totalNQueens(int n) {
        col.assign(n,false);
        diag1.assign(2*n-1,false);
        diag2.assign(2*n-1,false);
        f(0,n);
        return cnt;
    }
};