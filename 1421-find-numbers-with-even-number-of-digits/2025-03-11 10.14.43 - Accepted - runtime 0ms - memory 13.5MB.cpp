class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt=0;
        for( int i : nums){
            if(~countDigits(i)&1) cnt++;
        }
        return cnt;
        
    }
    int countDigits(int num){
        int count=0;
        while(num){
            count++;
            num=num/10;
        }
        return count;
    }
};