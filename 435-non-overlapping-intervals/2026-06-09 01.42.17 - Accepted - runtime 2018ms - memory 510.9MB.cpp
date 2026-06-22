class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int> a, vector<int> b){return a[1]<b[1];});
        int n = intervals.size();
        int cnt =0;
        int last =intervals[0][1];
        for(int i =0;i<n-1;i++ ){
            if(last> intervals[i+1][0]){
                cnt++;
                
            }else last =intervals[i+1][1];
        }
        return cnt;
    }
};