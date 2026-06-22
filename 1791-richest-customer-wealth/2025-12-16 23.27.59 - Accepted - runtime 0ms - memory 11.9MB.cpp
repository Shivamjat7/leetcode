class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth=0;
        for(vector<int> vec: accounts){
            int sum = accumulate(vec.begin(),vec.end(),0);
            maxWealth=max(maxWealth,sum);
        }
        return maxWealth;
    }
};