class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if(m*n!=r*c)return mat;
        vector<vector<int>>res(r,vector<int>(c));
        int i =0;
        for(auto rows:mat){
            for(auto val:rows){
               res[i/c][i%c]=val;
               i++;
            }
        }
        return res;
    }
};