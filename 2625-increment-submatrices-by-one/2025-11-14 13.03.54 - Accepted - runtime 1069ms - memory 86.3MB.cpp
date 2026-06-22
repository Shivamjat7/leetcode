class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>mat(n, vector<int>(n,0));
        for(auto &querie:queries){
            int r1=querie[0];
            int c1=querie[1];
            int r2=querie[2];
            int c2=querie[3];
            for(int i=r1;i<=r2;i++){
                for(int j=c1;j<=c2;j++){
                    mat[i][j]++;
                }
            }
        }
        return mat;
    }
};