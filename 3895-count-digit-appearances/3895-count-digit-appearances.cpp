class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int cnt=0;
        for(int val:nums){
            int temp=val;
            if(digit==0 && temp==0)cnt++;
            while(temp>0){
                int d = temp%10;
                temp = temp/10;
                if(d==digit)cnt++;
            }
        }
        return cnt;
    }
};