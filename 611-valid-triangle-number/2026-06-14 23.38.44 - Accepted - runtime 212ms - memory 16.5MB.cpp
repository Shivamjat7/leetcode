class Solution {
public:
    int isTriangle(int a,int b ,int c){
        return a+b>c;
    }
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int cnt =0;
        sort(nums.begin(),nums.end());
       for(int i =0;i<n;i++){
        for(int j =i+1;j<n;j++){
            int low =j+1;
            int high=n-1;
            while(high>=low){
                int mid = (high+low)/2;
                if(isTriangle(nums[i],nums[j],nums[mid])){
                    low=mid+1;
                }else high =mid-1;
            }
            cnt += low-j-1;
        }
       }
       return cnt;
    }
};