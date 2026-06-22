class Solution {
public:
  
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> prev(m+1,-1e9);
        vector<int> curr(m+1,-1e9);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
              int prod= nums1[i-1]*nums2[j-1];
              curr[j]=max({prod,prod+prev[j-1],prev[j],curr[j-1]});
            }
            prev=curr;
        }
        return curr[m];
    }
};