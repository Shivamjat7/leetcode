class Solution {
    vector<vector<int>> ans;
    vector<int> curr;
public:
    void backtrack(int i,vector<int>& candidates, int target){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        if(i>=candidates.size()|| target<0)return;
        curr.push_back(candidates[i]);
        backtrack(i,candidates,target-candidates[i]);
        curr.pop_back();
        backtrack(i+1,candidates,target);



    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(0,candidates,target);
        return ans;
    }
};