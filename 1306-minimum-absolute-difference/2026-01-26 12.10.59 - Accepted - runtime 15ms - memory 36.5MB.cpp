class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int minDiff =INT_MAX;
        sort(arr.begin(),arr.end());
        for(int i =0;i<arr.size()-1;i++){
            int diff = abs(arr[i+1]-arr[i]);
            minDiff=min(diff,minDiff);
        }
        vector<vector<int>> ans;
         for(int i =0;i<arr.size()-1;i++){
            int diff = abs(arr[i+1]-arr[i]);
            if(diff ==minDiff) ans.push_back({arr[i],arr[i+1]});
        }
        return ans;
    }
};