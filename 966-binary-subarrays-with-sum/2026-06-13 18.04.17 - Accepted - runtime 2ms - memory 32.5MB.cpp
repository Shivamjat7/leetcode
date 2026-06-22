class Solution {
public:
    int atmost(vector<int>&arr,int k){
        if(k<0)return 0;
        int cnt =0;
         long sum =0;
        int n =arr.size();
        int l=0,r=0;
        while(r<n){
            sum+=arr[r];
            while(sum>k){
                sum-=arr[l];
                l++;
            }
            if (sum<=k){
                cnt+=r-l+1;
            }
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums,goal)-atmost(nums,goal-1);
    }
};