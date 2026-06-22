class Solution {
public:
    vector<int> lis(vector<int>&nums){
        if(nums.empty())return {0,0,0};
        int currStart=0,bestStart=0,bestEnd=0;
        int currLen=1,mxLen=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1])continue;
            else if(nums[i]==nums[i-1]+1){
                currLen++;
            }else{
                currStart=i;
                currLen=1;
            }

            if(currLen>mxLen){
                mxLen=currLen;
                bestStart=currStart;
                bestEnd=i;
            }
        }
        return {nums[bestStart],nums[bestEnd]};
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        auto h=lis(hBars);
        auto v=lis(vBars);
        int len = min(h[1]-h[0]+2,v[1]-v[0]+2);
        return len*len;

    }
};