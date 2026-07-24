class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        long long total = accumulate(arr.begin(),arr.end(),0LL);
        if(total%3!=0)return false;
        long long sum=0;
        int cnt =0;
        for(auto val :arr){
            sum+=val;
        
            if(sum==total/3){
                cnt++;
                sum=0;
            }
        }
        return  cnt>=3;
    
    }
};