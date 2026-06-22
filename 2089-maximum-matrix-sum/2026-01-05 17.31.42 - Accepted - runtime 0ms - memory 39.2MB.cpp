class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int neg=0;
        int n=matrix.size();
        long long sum =0;
        int mn=INT_MAX;
        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                sum+=abs(matrix[i][j]);
                mn=min(mn,abs(matrix[i][j]));
                if(matrix[i][j]<0){
                    neg++;
                }
            }
        }
        sum+= neg%2==0?0:- 2*mn;
        return sum;
    }
};