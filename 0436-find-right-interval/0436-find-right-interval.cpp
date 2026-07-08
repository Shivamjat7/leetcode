class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        for(int i =0;i<n;i++){
            intervals[i].push_back(i);
        }
        vector<int>ans(n,-1);
        sort(intervals.begin(),intervals.end(),[&](auto a,auto b){
            return a[0]<b[0];
        });
        for(auto &in:intervals){
            int low =0,high=n-1;
            int index=-1;
            while(low<=high){
                int mid  = low + (high-low)/2;
                if(intervals[mid][0]>=in[1]){
                    index =intervals[mid][2];
                    high=mid-1;
                }else low = mid+1;
            }
            ans[in[2]]=index;
        }
return ans;
    }
};