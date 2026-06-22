class Solution {
    vector<vector<int>> ans;
    vector<int> temp;
    void backtracking(int i,int k,int n){
        if(temp.size()==k && n==0){
            ans.push_back(temp);
            return;
        }

        for(int j=i;j<=9;j++){
            if(j>n) break;
            temp.push_back(j);
            backtracking(j+1,k,n-j);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(1,k,n);
        return ans;
    }
};