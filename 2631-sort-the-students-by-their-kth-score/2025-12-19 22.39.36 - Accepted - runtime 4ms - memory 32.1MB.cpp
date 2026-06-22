class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int n = score.size();
        int m = score[0].size();
        
        for(int i =0;i<n-1;i++){
            int ind=i;
            for(int m =i;m<n;m++){
                if(score[m][k]>score[ind][k]) ind=m;
            }
            for(int j=0;j<m;j++){
                swap(score[i][j],score[ind][j]);
            }
        }
        return score;
    }
};