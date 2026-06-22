class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end(),[&](auto a,auto b){
            return a[0]<b[0];
        });
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){

            vector<int> last = ans.back();
             if(last[1]>=intervals[i][0] && last[1]>intervals[i][1] )continue;

            if(last[1]>=intervals[i][0] && last[1]<intervals[i][1]||(last[0]<=intervals[i][0] && last[1]>=intervals[i][0])){
                ans.back()[1]=intervals[i][1];
                
            }
                
            

            else if( ans.back()[0]==intervals[i][0]&& ans.back()[1]==intervals[i][1])continue;
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};