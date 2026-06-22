class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefixSum;
        int count=0;
        prefixSum[0]=1;
        long currentSum =0;
        for(int num:nums){
            currentSum += num;
            if(prefixSum.find(currentSum-k)!=prefixSum.end()){
                count += prefixSum[currentSum-k];
            }
            prefixSum[currentSum]++;
        }
        return count;

    }
};