class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n<3)return n;
        int cnt =0;
        while(n>0){
            n = n>>1;
            cnt++;
        }
        
        int ans = 1<<cnt;
        return ans;
    }
};