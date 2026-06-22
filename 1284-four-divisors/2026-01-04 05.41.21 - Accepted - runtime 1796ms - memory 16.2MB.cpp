class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum =0;
        for(int num:nums){
            int cnt=1;
            int s=num;
            for(int i=1;i<num;i++ ){
                if(num%i==0){
                    cnt++;
                    s+=i;
                }
                if(cnt>4) break;
            }
            if(cnt==4)sum+=s;
        }
        return sum;
    }
};