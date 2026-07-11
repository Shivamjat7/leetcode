class Solution {
public:
    int setSize(int i,vector<int>&nums,vector<int>&vis){

        int cnt=0;
        while(true){
            if(vis[i])break;
            vis[i]=1;
            cnt++;
            i=nums[i];
        }
        return cnt;
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