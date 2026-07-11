class Solution {
public:
    int setSize(int i,vector<int>&nums,vector<int>&vis){
        unordered_set<int>st;

        while(true){
            if(st.contains(nums[i]))break;
            vis[nums[i]]=1;
            st.insert(nums[i]);
            i=nums[i];
        }
        return st.size();
    }
    int arrayNesting(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        vector<int>vis(n,0);
        for(int i=0;i<nums.size();i++){
            if(!vis[nums[i]]){
            ans = max(ans,setSize(i,nums,vis));}
        }
        return ans;
    }
};