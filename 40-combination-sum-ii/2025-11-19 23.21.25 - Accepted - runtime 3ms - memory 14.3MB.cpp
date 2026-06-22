class Solution {
    vector<vector<int>> ans;
    vector<int> temp;
    void backtracking(int idx,vector<int>& candidates,int target){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        for(int i =idx;i<candidates.size();i++ ){
            if(i>idx && candidates[i]==candidates[i-1])continue;
            if(candidates[i]>target) break;
            temp.push_back(candidates[i]);
            backtracking(i+1,candidates,target-candidates[i]);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backtracking(0,candidates,target);
        return ans;
    }
};