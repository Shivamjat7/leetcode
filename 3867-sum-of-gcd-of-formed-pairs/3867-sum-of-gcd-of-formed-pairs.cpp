class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>pref(n,0);
        int mx =INT_MIN;
        for(int i =0;i<n;i++){
            mx = max(nums[i],mx);
            pref[i]=gcd(mx,nums[i]);
        }
        sort(pref.begin(),pref.end());
        long long sum =0;
        int low =0;
        int high= n-1;
        while(low<high){
            int val = gcd(pref[low],pref[high]);
            low++;
            high--;
            sum+=val;
        }
        return sum;
    }
};