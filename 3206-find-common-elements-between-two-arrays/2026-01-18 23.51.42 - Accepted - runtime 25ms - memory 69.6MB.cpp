class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st1(nums1.begin(),nums1.end());
        unordered_set<int>st2(nums2.begin(),nums2.end());
        int ans1=0,ans2=0;
        for(int val:nums1){
            if(st2.count(val))ans1++;
        }
        for(int val:nums2){
            if(st1.count(val))ans2++;
        }
        return{ans1,ans2};
        
    }
};