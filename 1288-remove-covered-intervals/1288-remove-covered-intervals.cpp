class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[&](auto x,auto y){
            if(x[0]==y[0])return x[1]>y[1];
            return x[0]<y[0];
        });
        vector<int>last = intervals[0];
        int ans =1;
        for(int i=1;i<intervals.size();i++){
            int a = intervals[i][0];
            int b = intervals[i][1];
            if(a<=last[0] && last[1]<=b){
                last=intervals[i];
            }else if(last[0]<=a && b<=last[1]){

            }else{
                last=intervals[i];
                ans++;
            }
            

                    }
                    return ans;
    }
};