class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int cnt =0;
        int maxOR=0;
        for(int mask=0;mask<(1<<n);mask++){
            int OR =0;
            for(int i =0;i<n;i++){
                if(mask&(1<<i)){
                    OR=OR|nums[i];
                }
            }
            if(OR>maxOR){
                maxOR=OR;
                cnt=1;
            }else if(OR==maxOR)cnt++;
        }
        return cnt;
    }
};